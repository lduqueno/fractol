#pragma OPENCL EXTENSION cl_khr_fp64 : enable

__kernel void burningship(__global int* pixels, int win_height, int win_width,
					int max_iteration, double zoom, double move_x, double move_y,
					double cst_r, double cst_i, int color_count, __global int *colors)
{
	int iteration = 0;
	int x = get_global_id(0);
	int y = get_global_id(1);
	double cRe = 1.5 * (x - win_width / 2) / (0.45 * zoom * win_width) + move_x - 0.4;
	double cIm = 1.5 * (y - win_height / 2) / (0.45 * zoom * win_height) + move_y - 0.5;
	double constantsRe = cRe;
	double constantsIm = cIm;

	double powRe = cRe * cRe;
	double powIm = cIm * cIm;

	while (iteration < max_iteration && powRe + powIm < 4)
	{
		cIm = fabs(2 * cRe * cIm) + constantsIm;
		cRe = fabs(powRe - powIm + constantsRe);
		powRe = cRe * cRe;
		powIm = cIm * cIm;
		iteration++;
	}
	if (iteration == max_iteration)
		pixels[y * win_width + x] = 0x00000;
	else
		pixels[y * win_width + x] = colors[iteration % color_count];
}
