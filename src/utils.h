#ifndef UTILS__
#define UTILS__

extern void seed_random_num(void);
extern int get_random_num(int min, int max);
extern int get_cell_x_pos(int cell_index);
extern int get_cell_y_pos(int cell_index);
extern void process_input(void);

#endif