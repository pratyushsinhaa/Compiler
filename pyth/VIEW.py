import platform
import time
import sys
import binascii
import marshal
import dis
import struct


def view_pyc_file(path):
    """Read and display a content of the Python`s bytecode in a pyc-file."""

    file = open(path, 'rb')

    magic = file.read(4)
    timestamp = file.read(4)
    size = None

    if sys.version_info.major == 3 and sys.version_info.minor >= 3:
        size = file.read(4)
        size = struct.unpack('I', size)[0]

    code = marshal.load(file)

    magic = binascii.hexlify(magic).decode('utf-8')
    timestamp = time.asctime(time.localtime(struct.unpack('I', timestamp)[0]))

    dis.disassemble(code)

    print('-' * 80)
    print(
        'Python version: {}\nMagic code: {}\nTimestamp: {}\nSize: {}'
        .format(platform.python_version(), magic, timestamp, size)
    )

    file.close()


if __name__ == '__main__':
    view_pyc_file("/Users/pratyushsinha/Github/Compiler/pyth/test1.py")