__kernel void hello(__global int* pixels, __global float *data)
{
	int x = get_global_id(0);
	int y = get_global_id(1);
	int win_height = convert_int(data[0]);
	int win_width = convert_int(data[1]);
	float zoom = data[2];
	float move_x = data[3];
	float move_y = data[4];
	printf("Y=%d, X=%d, Pixel id=%d\n", y, x, y * win_width + x);
	printf("H=%d, W=%d, Z=%f, M_X=%f, M_Y=%f\n", win_height, win_width, zoom, move_x, move_y);
	pixels[y * win_width + x] = y * win_width + x;



}
