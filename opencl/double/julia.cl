#pragma OPENCL EXTENSION cl_khr_fp64 : enable

__kernel void julia_double(__global int* pixels, __global double *data, __global int *colors)
{
	int iteration = 0;
	int x = get_global_id(0);
	int y = get_global_id(1);
	int win_height = data[0];
	int win_width = data[1];
	int max_iteration = data[2];
	double zoom = data[3];
	double move_x = data[4];
	double move_y = data[5];
	int color_count = data[6];
	double cRe = 1.5 * (x - win_width / 2) / (0.5 * zoom * win_width) + move_x;
	double cIm = (y - win_height / 2) / (0.5 * zoom * win_height) + move_y;
	double powRe = cRe * cRe;
	double powIm = cIm * cIm;

	while (iteration < max_iteration && powRe + powIm < 4)
	{
		cIm = 2 * cRe * cIm + 0.27015;
		cRe = powRe - powIm + -0.7;
		powRe = cRe * cRe;
		powIm = cIm * cIm;
		iteration++;
	}
	if (iteration == max_iteration)
		pixels[y * win_width + x] = 0x00000;
	else
		pixels[y * win_width + x] = colors[iteration % color_count];
}
