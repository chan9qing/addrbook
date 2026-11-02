# 通讯录

一个命令行通讯录，支持增删查和自动存盘。

## 编译

需要 gcc 和 make。

```
make
```

## 运行

```
make run（powershell版本：mingw32-make run)
```

数据存在当前目录的 `contacts.txt`，程序退出时自动保存。

## 清理

```
make clean
```

## 文件结构

| 文件 | 职责 |
|------|------|
| `main.c` | 菜单循环和分派 |
| `contact.c/.h` | 联系人增删查 |
| `storage.c/.h` | 存盘和读盘 |
| `ui.c/.h` | 打印和读输入 |
| `util.c/h` | 一个单纯的显示功能 |

- 增加联系人信息修改
-  最多 100 个联系人（上限见 `include/contact.h` 的 `MAX_CONTACTS`）
- 不能重名
- 这是说明1
