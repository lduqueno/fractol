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

inline cfloat f(cfloat c)
{
	return zsubtract(zpow(c, 3), (cfloat)(1.0, 0.0));
}

inline cfloat df(cfloat c)
{
	return zmult(zmult(c, c), (cfloat)(3.0, 0.0));
}

__kernel void newton(__global int* pixels, int win_height, int win_width,
					int max_iteration, double zoom, double move_x, double move_y,
					double cst_r, double cst_i, int color_count, __global int *colors,
					__global int *iterations)
{
	int iteration = 0;
	int x = get_global_id(0);
	int y = get_global_id(1);
	cfloat c = (cfloat)((x - win_width / 2) / (0.01 * zoom * win_width) + 30 * move_x,
		(y - win_height / 2) / (0.01 * zoom * win_height) + 30 * move_y);
	cfloat func;
	int pixel_id = y * win_width + x;

	while (iteration < max_iteration)
	{
		func = f(c);
		if (zabs(func) < 0.0001)
			break ;
		c = zsubtract(c, zdiv(func, df(c)));
		iteration++;
	}
	if (iteration == max_iteration)
		pixels[pixel_id] = 0x00000;
	else
		pixels[pixel_id] = colors[iteration % color_count];
	iterations[pixel_id] = iteration;
}
