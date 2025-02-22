# TZVR-IT-2

## � �������

������ ������� ���������� ���������� �� C++ ��������� ������ �������������� �������� (����, �����������, �������������), ����������� �� ������������ ������.

## ������������� ������

- `GeometricShape` - ����������� ����� ��� �������������� �����.
- `Circle` - �����, ����������� ����.
- `Triangle` - �����, ����������� �����������.
- `Rectangle` - �����, ����������� �������������.

## �����������

- � ������ ������ ���������� ����� ������� �������.
- ����������� ���������� ������� �������������� ����� �� �������.
- ��������� ��������� � ������� ��������� ������� ��� �������� ��������� �������.

## ������ �������

### ����� Visual Studio

1. �������� Visual Studio.
2. ������� **"����������� �����������"**.
3. �������� ������ �� ����������� GitHub.
4. ��������� �������� �������.
5. ������� **"������"** (��� F5) ��� ������ ����������.

### ����� ��������� ������ (MSVC)

1. �������� **x64 Native Tools Command Prompt for VS**.
2. ��������� � ����� � ��������.
3. ������������� ������ ��������:
   ```sh
   cl /EHsc /std:c++17 /Fe:geometry_app.exe TZVR-IT.cpp Circle.cpp Rectangle.cpp Triangle.cpp
   ```
4. ��������� ����������:
   ```sh
   geometry_app.exe
   ```

## �������� �����

- `TZVR-IT.cpp` - ������� ���� �������.
- `GeomtricShape.h` - ���������� ������� �������������� �����.


