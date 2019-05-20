__kernel void tricorn_float(__global int* pixels, int win_height,
			int win_width, int max_iteration, float zoom, float move_x,
			float move_y, int color_count, __global int *colors)
{
	int iteration = 0;
	int x = get_global_id(0);
	int y = get_global_id(1);
	float cRe = 0;
	float cIm = 0;
	float constantRe = 3.0 * (x - win_width / 2) / (0.8 * zoom * win_width) + move_x - 0.025;
	float constantIm = 3.0 * (y - win_height / 2) / (0.8 * zoom * win_height) + move_y;

	float powRe = cRe * cRe;
	float powIm = cIm * cIm;

	while (iteration < max_iteration && powRe + powIm <= 4)
	{
		cIm = -2 * cRe * cIm + constantIm;
		cRe = powRe - powIm + constantRe;
		powRe = cRe * cRe;
		powIm = cIm * cIm;
		iteration++;
	}
	if (iteration == max_iteration)
		pixels[y * win_width + x] = 0x00000;
	else
		pixels[y * win_width + x] = colors[iteration % color_count];
}