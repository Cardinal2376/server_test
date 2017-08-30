import _judger
import os

#g++ 2017083010211324021.cpp -o main
if os.system("g++ /root/server_test/uploads/main.cpp -o main"):
    print("compile error")
    exit(1)

ret = _judger.run(max_cpu_time=1000,
                  max_real_time=2000,
                  max_memory=128 * 1024 * 1024,
                  max_process_number=200,
                  max_output_size=10000,
                  max_stack=32 * 1024 * 1024,
                  # five args above can be _judger.UNLIMITED
                  exe_path="main",
                  input_path="in.txt",
                  output_path="out.txt",
                  error_path="err.txt",
                  args=[],
                  # can be empty list
                  env=[],
                  log_path="judger.log",
                  # can be None
                  seccomp_rule_name="c_cpp",
                  uid=0,
                  gid=0)
print(ret)