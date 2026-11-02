#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

/* qsort 比较函数：数组元素是 const Contact *，所以形参是它的指针 */
static int cmp_contact_by_name(const void *a, const void *b) {
    const Contact *ca = *(const Contact *const *)a;
    const Contact *cb = *(const Contact *const *)b;

    int r = strcmp(ca->name, cb->name);
    if (r != 0) return r;
    /* 同名时再按电话排，保证输出顺序稳定、可复现 */
    return strcmp(ca->phone, cb->phone);
}

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

    /* b 是只读的，不能就地排序；这里排“指向联系人的指针”，
       既保持原有存储顺序（存盘顺序不变），又不复制联系人数据。 */
    const Contact *sorted[MAX_CONTACTS];
    for (int i = 0; i < b->count; i++) {
        sorted[i] = &b->items[i];
    }
    qsort(sorted, (size_t)b->count, sizeof(sorted[0]), cmp_contact_by_name);

    for (int i = 0; i < b->count; i++) {
        printf("%-20s %s %s\n", sorted[i]->name, sorted[i]->phone, sorted[i]->email);
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
//这是神秘的注释
//hello
//hbq