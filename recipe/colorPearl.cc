#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "stdio.h"

#define N 8
#define M 30

struct listnode {
	struct listnode* next;
};

void list_insert(struct listnode* head, struct listnode* item)
{
	if (head) {	/* insert after of head */
		struct listnode* next = head->next;
		head->next = item;
		item->next = next;
	} else {  /* below implement rounded linked list, tail will point to head */
		item->next = item;
	}
}

struct color_pearl {
	struct listnode list;
	int color;
};

struct context {
	int color_count[N];
	int color_map;
	int color_all_mask;
	int min_len;
	struct listnode* min_pointer;
	
	struct listnode* pearl_pointer;
	struct listnode* start_pointer;
	struct listnode* end_pointer;
	int current_len;
};

struct listnode* init_pearl_list(int m)
{
	struct listnode* head = 0;
	struct listnode* tail = 0;
	srand((unsigned)time(0));
	while (m--) {
		struct color_pearl* pearl = (struct color_pearl*)malloc(sizeof(color_pearl));
		pearl->color = rand()%N;
		list_insert(tail, &pearl->list);
		tail = &pearl->list;
		if (head==0) {
			head = &pearl->list;
		}
		printf("%d ", pearl->color);
	}
	printf("\n");
	return head;
}

void init_context(struct context* ctx, struct listnode* list)
{
	memset(ctx, 0, sizeof(struct context));
	ctx->pearl_pointer = ctx->start_pointer = ctx->end_pointer = list;
	for (int i = 0; i < N; i++)
		ctx->color_all_mask |= 1<<i;
	printf("color_all_mask = %0X\n", ctx->color_all_mask);
}

int main()
{
	struct listnode* pearl_list;
	struct context ctx;
	int finish = 0;
	struct color_pearl* pearl;
	printf("---start---\n");
	
	pearl_list = init_pearl_list(M);
	init_context(&ctx, pearl_list);
	while (!finish) {
		pearl = (struct color_pearl*)ctx.end_pointer;
		ctx.end_pointer = ctx.end_pointer->next;
		ctx.current_len++;
		ctx.color_count[pearl->color]++;
		ctx.color_map |= 1 << pearl->color;
		
		while (ctx.color_map == ctx.color_all_mask) {
			if (ctx.min_len==0 || ctx.min_len > ctx.current_len) {
				ctx.min_len = ctx.current_len;
				ctx.min_pointer = ctx.start_pointer;
			}
			pearl = (struct color_pearl*)ctx.start_pointer;
			ctx.start_pointer = ctx.start_pointer->next;
			ctx.current_len--;
			ctx.color_count[pearl->color]--;
			// remove duplicated color pearl, until keep all colors
			if (ctx.color_count[pearl->color]==0) {
				ctx.color_map &= ~(1<<pearl->color);
			}
			if (ctx.start_pointer==ctx.pearl_pointer)
				finish = 1;
		}
		if (ctx.end_pointer == ctx.start_pointer)
			finish = 1;
	}
	printf("min length = %d\n", ctx.min_len);
	if (ctx.min_len!=0) {
		pearl = (struct color_pearl*)ctx.min_pointer;
		for (int i = 0; i < ctx.min_len; i++) {
			printf("%d ", pearl->color);
			pearl = (struct color_pearl*)pearl->list.next;
		}
		printf("\n");
		printf("---end---\n");
	}
	return 0;
}

	
