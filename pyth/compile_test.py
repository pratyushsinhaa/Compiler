import py_compile
import os

pycache_dir = '__pycache__'
if not os.path.exists(pycache_dir):
    os.makedirs(pycache_dir)

print(f"Current working directory: {os.getcwd()}")
print(f"test.py exists: {os.path.isfile('test.py')}")

try:
    # Compile test.py and place the .pyc file in the __pycache__ directory
    py_compile.compile('test.py', cfile=os.path.join(pycache_dir, 'test.pyc'))
    print("Compilation successful. The .pyc file is created in the __pycache__ directory.")
except Exception as e:
    print(f"Compilation failed: {e}")