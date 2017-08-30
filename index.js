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
            var newpath = __dirname + "/uploads/main.cpp";

            //写文件
            fs.writeFile(newpath, fields.code, 'utf8', function(err) {
               if(err) throw err;
                console.log('file has been saved!');
				var exec = require('child_process').exec;
				var cmdStr = 'python ' + __dirname + '/demo.py';
				console.log(cmdStr);
				exec(cmdStr, function (err, stdout, stderr) {
					if (err) {
						console.log('error:' + stderr);
					} else {
						console.log(stdout);
						res.writeHead(200, {
							'content-type': 'text/html'
						});
						res.write(stdout);
						res.end("success!");
						var path = __dirname + "/out.txt";
						fs.readFile(path, function (err, data) {
							if (err) {
								throw err;
							}
							console.log("文件读取完毕");
							res.write(data);
							res.end("success!");
						});
					}
				});
            });
           
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

server.listen(3000,"182.92.182.233");


/**
 * Created by Cardinal on 2017/7/21.
 */
 /*
var http = require("http");
var formidable = require('formidable');
var util = require("util");
var fs = require("fs");
var sd = require("silly-datetime");
var path = require("path");

//创建服务器
var server = http.createServer(function (req, res) {
		//如果你的访问地址是这个，并且请求类型是post
		if (req.url == "/dopost" && req.method.toLowerCase() == "post") {
			//Creates a new incoming form.
			var form = new formidable.IncomingForm();
			//设置文件上传存放地址
			form.uploadDir = "./uploads";
			//执行里面的回调函数的时候，表单已经全部接收完毕了。
			form.parse(req, function (err, fields, files) {
				if (err) {
					throw err;
				}
				console.log(util.inspect({
						fields: fields,
						files: files
					}));

				//时间，使用了第三方模块，silly-datetime
				var ttt = sd.format(new Date(), 'YYYYMMDDHHmmss');
				var ran = parseInt(Math.random() * 89999 + 10000);
				var extname = "." + fields.lang;

				//新的路径由三个部分组成：时间戳、随机数、拓展名
				//Edit： 去掉了时间戳和随机数,测试版恒定为Test.cpp
				var newpath = __dirname + "main" + extname;

				//写文件
				fs.writeFile(newpath, fields.code, 'utf8', function (err) {
					if (err)
						throw err;
					console.log('file has benn saved!');
					var exec = require('child_process').exec;
					var cmdStr = 'python ' + __dirname + 'demo.py';
					console.log(cmdStr);
					exec(cmdStr, function (err, stdout, stderr) {
						if (err) {
							console.log('error:' + stderr);
						} else {
							console.log(stdout);
							res.writeHead(200, {
								'content-type': 'text/html'
							});
							res.write(stdout);
							var path = __dirname + "out.txt";
							fs.readFile(path, function (err, data) {
								if (err) {
									throw err;
								}
								console.log("文件读取完毕");
								res.write(data);
								res.end("success!");
							});
						}
					});
				});

				});
			} else if (req.url == "/") {
				//呈递form.html页面
				fs.readFile("./form.html", function (err, data) {
					res.writeHead(200, {
						'content-type': 'text/html'
					});
					res.end(data);
				})
			} else {
				res.writeHead(404, {
					'content-type': 'text/html'
				});
				res.end("404");
			}
		});

server.listen(3000, "182.92.182.233");
*/