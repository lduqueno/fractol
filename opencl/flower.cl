#pragma OPENCL EXTENSION cl_khr_fp64 : enable

typedef double2 cfloat;

inline float zabs(cfloat a){
	return sqrt(a.x*a.x + a.y*a.y);
}

inline cfloat zmult(cfloat a, cfloat b){
	return (cfloat)(a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x);
}

inline cfloat zdiv(cfloat a, cfloat b){
	return (cfloat)((a.x*b.x + a.y*b.y)/(b.x*b.x + b.y*b.y), (a.y*b.x - a.x*b.y)/(b.x*b.x + b.y*b.y));
}

inline cfloat zpow(cfloat a, int n)
{
	int i = 0;
	cfloat result = (cfloat)(1.0, 0.0);

	while (i < n)
	{
		result = zmult(result, a);
		i++;
	}
	return result;
}

inline cfloat zsubtract(cfloat a, cfloat b)
{
	return (cfloat)(a.x - b.x, a.y - b.y);
}

inline cfloat zadd(cfloat a, cfloat b)
{
	return (cfloat)(a.x + b.x, a.y + b.y);
}

__kernel void flower(__global int* pixels, int win_height, int win_width,
					int max_iteration, double zoom, double move_x, double move_y,
					double cst_r, double cst_i, int color_count, __global int *colors,
					__global int *iterations)
{
	int iteration = 0;
	int x = get_global_id(0);
	int y = get_global_id(1);
	cfloat c = (cfloat)(1.5 * (x - win_width / 2) / (0.31 * zoom * win_width) + 3 * move_x,
		1.5 * (y - win_height / 2) / (0.31 * zoom * win_height) + 3 * move_y);
	int pixel_id = y * win_width + x;
	cfloat add = (cfloat)(0.9, 0.0);

	while (iteration < max_iteration)
	{
		if (c.x * c.x + c.y * c.y >= 8)
			break ;
		c = zsubtract(zpow(zdiv(c, zpow(c, 3)), 4), add);
		iteration++;
	}
	if (iteration == max_iteration)
		pixels[pixel_id] = 0x00000;
	else
		pixels[pixel_id] = colors[iteration % color_count];
	iterations[pixel_id] = iteration;
}
