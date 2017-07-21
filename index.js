/**
 * Created by Cardinal on 2017/7/21.
 */
var http = require("http");
var formidable = require('formidable');
var util = require("util");
var fs = require("fs");
var sd = require("silly-datetime");
var path = require("path");


//创建服务器
var server = http.createServer(function(req,res){
    //如果你的访问地址是这个，并且请求类型是post
    if(req.url == "/dopost" && req.method.toLowerCase() == "post"){
        //Creates a new incoming form.
        var form = new formidable.IncomingForm();
        //设置文件上传存放地址
        form.uploadDir = "./uploads";
        //执行里面的回调函数的时候，表单已经全部接收完毕了。
        form.parse(req, function(err, fields, files) {
            if(err){
               throw err;
            }
            console.log(util.inspect({fields: fields, files: files}));

            //时间，使用了第三方模块，silly-datetime
            var ttt = sd.format(new Date(), 'YYYYMMDDHHmmss');
            var ran = parseInt(Math.random() * 89999 + 10000);
            var extname = "." + fields.lang;
			
            //新的路径由三个部分组成：时间戳、随机数、拓展名
            var newpath = __dirname + "/uploads/" + ttt + ran + extname;

            //写文件
            fs.writeFile(newpath, fields.code, 'utf8', function(err) {
               if(err) throw err;
                console.log('file has benn saved!');
            });
            res.writeHead(200, {'content-type': 'text/html'});
            res.end("success!");
        });
    }else if(req.url == "/"){
        //呈递form.html页面
        fs.readFile("./form.html",function(err,data){
            res.writeHead(200, {'content-type': 'text/html'});
            res.end(data);
        })
    }else{
        res.writeHead(404, {'content-type': 'text/html'});
        res.end("404");
    }
});

server.listen(3000,"localhost");