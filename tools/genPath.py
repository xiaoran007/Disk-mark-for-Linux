import re
import subprocess
import os

def gen():
    try:
        proc = subprocess.run(["pkg-config", "--cflags", "gtk4"], check=True, text=True, capture_output=True, cwd=os.getcwd(), timeout=2)
        res = proc.stdout
    except subprocess.CalledProcessError as e:
        print(f"Error.")
        print(e.stderr)
    except subprocess.TimeoutExpired:
        print(f"Error, Time OUT.")
    res = " " + res[:-1]
    res_split = res.split(" -I")[1:]
    paths = list()
    for i in res_split:
        paths.append("\"" + i + "\"")
    print(",".join(paths))


gen()

