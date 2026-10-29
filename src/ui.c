#include <stdio.h>
#include <string.h>
#include "ui.h"

void ui_menu(void) {
    printf("\n===== 通讯录 =====\n");
    printf("1  添加联系人\n");
    printf("2  删除\n");
    printf("3  查找\n");
    printf("4  列出全部\n");    
    printf("5  修改信息\n");    
    printf("0  保存并退出\n");
    printf("请选择: ");
}

void ui_show_all(const Book *b) {
    if (b->count == 0) {
        printf("(通讯录是空的)\n");
        return;
    }
    for (int i = 0; i < b->count; i++) {
        printf("%-20s %s %s\n", b->items[i].name, b->items[i].phone,b->items[i].email);
    }
    printf("共 %d 条\n", b->count);
}

void ui_read_line(const char *prompt, char *buf, int size) {
    printf("%s", prompt);
    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    int n = (int)strlen(buf);
    if (n > 0 && buf[n - 1] == '\n') {
        buf[n - 1] = '\0';
    }
}
