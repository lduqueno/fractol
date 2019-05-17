#pragma OPENCL EXTENSION cl_khr_fp64 : enable

__kernel void burningship_double(__global int* pixels, __global double *data, __global int *colors)
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
	double cRe = 1.5 * (x - win_width / 2) / (0.45 * zoom * win_width) + move_x - 0.4;
	double cIm = (y - win_height / 2) / (0.5 * zoom * win_height) + move_y - 0.3;
	double constantsRe = cRe;
	double constantsIm = cIm;

	double powRe = cRe * cRe;
	double powIm = cIm * cIm;

	while (iteration < max_iteration && powRe + powIm < 4)
	{
		cIm = dabs(2 * cRe * cIm) + constantsIm;
		cRe = dabs(powRe - powIm + constantsRe);
		powRe = cRe * cRe;
		powIm = cIm * cIm;
		iteration++;
	}
	if (iteration == max_iteration)
		pixels[y * win_width + x] = 0x00000;
	else
		pixels[y * win_width + x] = colors[iteration % color_count];
}
