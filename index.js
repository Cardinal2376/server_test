/**
 * Created by Cardinal on 2017/7/21.
 */
var http = require("http");
var formidable = require('formidable');
var util = require("util");
var fs = require("fs");
var sd = require("silly-datetime");
var path = require("path");


//����������
var server = http.createServer(function(req,res){
    //�����ķ��ʵ�ַ���������������������post
    if(req.url == "/dopost" && req.method.toLowerCase() == "post"){
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
            var extname = "." + fields.lang;
			
            //�µ�·��������������ɣ�ʱ��������������չ��
            var newpath = __dirname + "/main.cpp";

            //д�ļ�
            fs.writeFile(newpath, fields.code, 'utf8', function(err) {
               if(err) throw err;
                console.log('file has been saved!');
				/*
				var exec = require('child_process').exec;
				
				var cmdStr = 'python ' + __dirname + '/demo.py';
				console.log(cmdStr);
				exec(cmdStr, function (err, stdout, stderr) {
					if (err) {
						console.log('error:' + stderr);
					} else {
						console.log(stdout);
						
					}
				});
				*/
				var child = require('child_process');
				var du = child.spawn('sudo', ['python', 'run.py', 'main.cpp', 'out.txt', 'g++']);
				//var dataObject = new Object();
				du.stdout.on('data', function (data) {
					console.log('stdout: ' + data);
					res.write(data);
				});
				du.stderr.on('data', function (data) {
					console.log('stderr: ' + data);
				});
				du.on('exit', function (code) {
					console.log('child process exited with code ' + code);
					var path = __dirname + "/out.txt";
					fs.readFile(path, function (err, data) {
						if (err) {
							throw err;
						}
						console.log("File Read Successfully");
						res.end(data);
					});
				});
            });
           
        });
    }else if(req.url == "/"){
        //�ʵ�form.htmlҳ��
        fs.readFile("./form.html",function(err,data){
            res.writeHead(200, {'content-type': 'text/html'});
            res.end(data);
        })
    }else{
        res.writeHead(404, {'content-type': 'text/html'});
        res.end("404");
    }
});

server.listen(3000,"182.92.182.233");
