#pragma OPENCL EXTENSION cl_khr_fp64 : enable

__kernel void mandelbrot(__global int* pixels, int win_height, int win_width,
					int max_iteration, double zoom, double move_x, double move_y,
					double cst_r, double cst_i, int color_count, __global int *colors,
					__global int *iterations)
{
	int iteration = 0;
	int x = get_global_id(0);
	int y = get_global_id(1);
	double cRe = 0;
	double cIm = 0;
	double constantRe = (x - win_width / 2) / (0.38 * zoom * win_width) + move_x - 0.5;
	double constantIm = (y - win_height / 2) / (0.38 * zoom * win_height) + move_y;
	double powRe = cRe * cRe;
	double powIm = cIm * cIm;
	int pixel_id = y * win_width + x;

	while (iteration < max_iteration && powRe + powIm <= 4)
	{
		cIm = 2 * cRe * cIm + constantIm;
		cRe = powRe - powIm + constantRe;
		powRe = cRe * cRe;
		powIm = cIm * cIm;
		iteration++;
	}
	if (iteration == max_iteration)
		pixels[pixel_id] = 0x00000;
	else
		pixels[pixel_id] = colors[iteration % color_count];
	iterations[pixel_id] = iteration;
}
