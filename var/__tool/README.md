1. NDK�� �ٿ�ε�
https://developer.android.com/ndk/downloads?hl=ko

2. �ȵ���̵� �� ü�� ����
$ python3 android-ndk-r21b/build/tools/make_standalone_toolchain.py --arch x86  --api 24  --install-dir=my-toolchain-24

3. ũ�ν� ������
$ my-toolchain/bin/i686-linux-android-clang -o example example.c
�� i686=32bit x86_64=64bit

4. dockcross �� �̿��� ũ�ν� ������
docker run --rm -v /root/data:/work dockcross/linux-x86 bash -c 'my-toolchain/bin/i686-linux-android-clang -o example example.c'

5. elf-cleaner (API22 ���� ��Ŀ ��� �ߴµ� �̸� �����Ѵ�.)
git clone https://github.com/termux/termux-elf-cleaner.git
make
termux-elf-cleaner <filenames>
