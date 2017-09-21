#!/usr/bin/python
# -*- coding: UTF-8 -*-

import _judger
import os
import subprocess
import sys
import json

#python main.py input_file output_file language(gcc/g++/java)
input_file = sys.argv[1]
ss = input_file.split('.', 2)
exe_file = ss[0]
output_file = sys.argv[2]
language = sys.argv[3]
language_map = {
    "gcc"  : "gcc",
    "g++"  : "g++",
    "java" : "javac",
    "python": "python",
}

if language == "java" or language == "python":
    cmd = language_map[language] + " " + input_file
else:
    cmd = language_map[language] + " ./uploads/json_reader.cpp ./uploads/json_value.cpp ./uploads/json_writer.cpp " + input_file + " -o " + exe_file

p = subprocess.Popen(cmd, shell=True, cwd=os.getcwd(), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
out, err = p.communicate()# 获取编译错误信息

ce_meg = dict()
if p.returncode:
    ce_meg = dict(signal=-1, output=out, error=err)
    print(json.dumps(ce_meg).encode('utf-8'))
    exit(1)
else:
    if language == "java" or language == "python":
        ce_meg = dict(signal=0, output=out, error=err)
        print(json.dumps(ce_meg).encode('utf-8'))
        exit(1)

    ret = _judger.run(max_cpu_time=1000,
                      max_real_time=2000,
                      max_memory= 1024 * 1024 * 1024,
                      max_process_number=200,
                      max_output_size=1000000,
                      max_stack=32 * 1024 * 1024,
                      # five args above can be _judger.UNLIMITED
                      exe_path=exe_file,
                      input_path="/dev/null",
                      # can not be empty
                      output_path=output_file,
                      error_path="error.log",
                      args=[],
                      # can be empty list
                      env=[],
                      log_path="judger.log",
                      # can be None
                      seccomp_rule_name="c_cpp",
                      uid=0,
                      gid=0)
    print(ret)
