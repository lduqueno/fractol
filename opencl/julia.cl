typedef struct
{
    float r;
    float i;
} t_complex;


__kernel void julia(__global int* pixels, __global float *data)
{
	int x = get_global_id(0);
	int y = get_global_id(1);
	int win_height = convert_int(data[0]);
	int win_width = convert_int(data[1]);
	int max_iteration = convert_int(data[2]);
	float zoom = data[3];
	float move_x = data[4];
	float move_y = data[5];


	int			iteration = 0;
	float		cRe;
	float		cIm;
	float		powRe;
	float		powIm;

	cRe = 1.5 * (x - win_width / 2) / (0.5 * zoom * win_width) + move_x;
	cIm = (y - win_height / 2) / (0.5 * zoom * win_height) + move_y;
	powRe = cRe * cRe;
	powIm = cIm * cIm;
	while (iteration < max_iteration && powRe + powIm < 4)
	{
		cIm = 2 * cRe * cIm + 0.27015;
		cRe = powRe - powIm + -0.7;
		powRe = cRe * cRe;
		powIm = cIm * cIm;
		iteration++;
	}
	pixels[y * win_width + x] = (0xFFFFFF / max_iteration * iteration / 10);
}
