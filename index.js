/**
 * Created by Cardinal on 2017/7/21.
 */
var http = require("http");
var formidable = require('formidable');
var util = require("util");
var fs = require("fs");
var sd = require("silly-datetime");
var path = require("path");
var url = require("url");
//����������
var server = http.createServer(function(req,res){
    //�����ķ��ʵ�ַ���������������������post
    if(req.url == "/dopost" && req.method.toLowerCase() == "post"){
		res.setHeader('Access-Control-Allow-Origin', '*');
        //Creates a new incoming form.
        var form = new formidable.IncomingForm();
        //�����ļ��ϴ���ŵ�ַ
        form.uploadDir = "./uploads";
        //ִ������Ļص�������ʱ�򣬱��Ѿ�ȫ����������ˡ�
        form.parse(req, function(err, fields, files) {
            if(err){
               throw err;
            }
            console.log(util.inspect({fields: fields, files: files}));

            //ʱ�䣬ʹ���˵�����ģ�飬silly-datetime
            var ttt = sd.format(new Date(), 'YYYYMMDDHHmmss');
            var ran = parseInt(Math.random() * 89999 + 10000);
			
            //�µ�·��������������ɣ�ʱ��������������չ��
            var ext = "";
            var langstr = "";
            if(fields.lang == "cpp") {
              langstr = "g++";
              ext = ".cpp";
            }
            else if(fields.lang == "python") {
              langstr = "python";
              ext = ".py";
            }
            var newpath = __dirname + "/" + ttt + ran + ext;
            var outpath = __dirname + "/" + ttt + ran + "out.txt";
            
        
            //д�ļ�
            fs.writeFile(newpath, fields.code, 'utf8', function(err) {
                if(err) throw err;
                console.log('file has been saved!');
                var child = require('child_process');
                var du = child.spawn('sudo', ['python', 'run.py', newpath, outpath, langstr]);
                //var dataObject = new Object();
                var state = "";
                du.stdout.on('data', function (data) {
                  //console.log('stdout: ' + data);
                  state += data;
                });
                du.stderr.on('data', function (data) {
                  console.log('stderr: ' + data);
                });
                du.on('exit', function (code) {
                  console.log('stdout: ' + state);
                  state = eval('(' + state + ')');
                  console.log('child process exited with code ' + code);
                  var result = new Object();
                  result.signal = state.signal;
                  result.error = state.error;
                  result.data = state.output;
                  result.result = state.result;
                  if(state.signal == 0 && fields.lang == "cpp") {
                    var path = outpath;
                    fs.readFile(path, function (err, data) {
                      if (err) {
                        throw err;
                      }
                      console.log("File Read Successfully");
                      result.data = "";
                      result.data += data;
                      console.log(result);
                      res.end(JSON.stringify(result));
                    });
                  } else {
                    console.log(result);
                    res.end(JSON.stringify(result));
                  }
                  
                });
            });
           
        });
    }else if(req.url == "/post" && req.method.toLowerCase() == "post"){
		//res.setHeader('Access-Control-Allow-Origin', '*');
		res.writeHead(200, {"Content-type":"text/html;charset=UTF-8","Access-Control-Allow-Origin":"*"});
		var alldata = "";
		
        req.addListener("data",function(chunk){
            alldata += chunk;
        });
        
        req.addListener("end",function(){
			console.log(alldata);
			var ttt = sd.format(new Date(), 'YYYYMMDDHHmmss');
			var ran = parseInt(Math.random() * 89999 + 10000);
			var newpath = __dirname + "/static/" + ttt + ran + ".json";
			fs.writeFile(newpath, alldata, 'utf8', function(err) {
			   if(err) throw err;
				console.log('file has been saved!');
				var str = ttt + ran;
				res.end(str);
			});
        });

       
    }else if(req.url == "/"){
		//�ʵ�form.htmlҳ��
		res.setHeader('Access-Control-Allow-Origin', '*');
        fs.readFile("./form.html",function(err,data){
            res.writeHead(200, {'content-type': 'text/html'});
            res.end(data);
        })
    } else {
		res.setHeader('Access-Control-Allow-Origin', '*');
		var pathname = url.parse(req.url).pathname;
		fs.readFile("./static/" + pathname + ".json",function(err,data){
			if(err){
				//������ļ������ڣ���Ӧ����404����
				fs.readFile("./static/404.html",function(err,data){
					res.writeHead(404,{"Content-type":"text/html;charset=UTF8"});
					res.end(data);
				});
				return;
			};
			res.writeHead(200,{"Content-type":"text/html"});
			res.end(data);
		});
	}
});
//server.listen(3000,"localhost");
server.listen(3000,"182.92.182.233");
