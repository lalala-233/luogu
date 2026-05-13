#!/usr/bin/env python3
"""
用法: ./script.py <filename>
功能:
  - 如果 <filename> 存在，则提取不含后缀的名字 basename，
    执行: make basename && ./basename < input.txt
  - 如果 <filename> 不存在，则将模板文件复制为 <filename>
"""

import os
import sys
import subprocess

# ========== 配置区 ==========
TEMPLATE_FILE = "../template.cpp"  # 当目标文件不存在时，复制此文件
INPUT_FILE = "test.txt"  # 运行时重定向的输入文件
# ============================


def get_basename_without_ext(filename):
    """返回去掉最后一个后缀的文件名（例如 'test.c' -> 'test'）"""
    base = os.path.basename(filename)
    # 只去掉最后一个点后面的后缀，如 foo.bar.c -> foo.bar
    return base.split(".")[0] if "." in base else base


def main():
    if len(sys.argv) != 2:
        print(f"用法: {sys.argv[0]} <文件名>", file=sys.stderr)
        sys.exit(1)

    target = sys.argv[1]

    if os.path.exists(target):
        basename = get_basename_without_ext(target)
        cmd = f"make {basename} && ./{basename} < {INPUT_FILE}"
        print(f"执行命令: {cmd}")
        try:
            subprocess.run(cmd, shell=True, check=True)
        except subprocess.CalledProcessError as e:
            print(f"命令执行失败，返回码: {e.returncode}", file=sys.stderr)
            sys.exit(e.returncode)
        except KeyboardInterrupt:
            print("\n用户中断", file=sys.stderr)
            sys.exit(130)
    else:
        if not os.path.exists(TEMPLATE_FILE):
            print(f"错误: 模板文件 '{TEMPLATE_FILE}' 不存在，无法复制", file=sys.stderr)
            sys.exit(1)
        cmd = f"cp {TEMPLATE_FILE} {target} && code {target}"
        print(f"执行命令: {cmd}")
        try:
            subprocess.run(cmd, shell=True, check=True)
        except subprocess.CalledProcessError as e:
            print(f"命令执行失败，返回码: {e.returncode}", file=sys.stderr)
            sys.exit(e.returncode)
        except KeyboardInterrupt:
            print("\n用户中断", file=sys.stderr)
            sys.exit(130)


if __name__ == "__main__":
    main()
