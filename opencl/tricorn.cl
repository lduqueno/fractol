__kernel void tricorn(__global int* pixels, __global float *data)
{
	int iteration = 0;
	int x = get_global_id(0);
	int y = get_global_id(1);
	int win_height = convert_int(data[0]);
	int win_width = convert_int(data[1]);
	int max_iteration = convert_int(data[2]);
	float zoom = data[3];
	float move_x = data[4];
	float move_y = data[5];
	float cRe = 0;
	float cIm = 0;
	float constantRe = 1.0 * (x - win_width / 2) / (0.5 * zoom * 0.8 * win_width) + move_x - 0.2;
	float constantIm = (y - win_height / 2) / (0.5 * zoom * win_height) + move_y;

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
		pixels[y * win_width + x] = (0xFFFFFF / max_iteration * iteration / 10);
}
