import py_compile
import os

print(f"Current working directory: {os.getcwd()}")
print(f"test2.py exists: {os.path.isfile('test2.py')}")

pycache_dir = '__pycache__'
if not os.path.exists(pycache_dir):
    os.makedirs(pycache_dir)
    print(f"Created directory: {pycache_dir}")

try:
    py_compile.compile('test2.py', cfile=os.path.join(pycache_dir, 'test2.pyc'))
    print("Compilation successful. The .pyc file is created in the __pycache__ directory.")
except Exception as e:
    print(f"Compilation failed: {e}")