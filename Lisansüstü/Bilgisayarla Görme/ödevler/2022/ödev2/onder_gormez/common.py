import numpy as numpy

def twoDimensionalGaussianKernel(sigma, kernel_size):
    number_of_samples = kernel_size
    max_range = int(number_of_samples / 2)
    range_vector = numpy.linspace(-max_range, max_range, number_of_samples)
    x , y = numpy.meshgrid(range_vector, range_vector)
    kernel = (1. / (2. * numpy.pi * sigma**2)) * numpy.exp(-(x**2 + y**2)/(2 * sigma**2))
    return kernel
