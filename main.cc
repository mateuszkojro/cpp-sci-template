#include <xtensor/xtensor.hpp>
#include <xtensor/xhistogram.hpp>
#include <xtensor/xio.hpp>
#include <sciplot/sciplot.hpp>

int main(int argc, char **argv) {
  xt::xtensor<double, 1> data = {1., 1., 2., 2., 3.};

  xt::xtensor<double, 1> count = xt::histogram(data, std::size_t(2));

  xt::xtensor<double, 1> bin_edges = xt::histogram_bin_edges(data, std::size_t(2));

  std::cout << bin_edges << std::endl;

  auto z = xt::linspace<double>(0, 100, 1000);

  // Construct x and y for each z so that a helix curve is defined
  std::vector<double> x, y;

  for (auto val: z) {
    x.push_back(val);
    y.push_back(sin(val));
  }

  // Create a Plot3D object
  sciplot::Plot plot;

  // Set the x, y, z labels
  plot.xlabel("x");
  plot.ylabel("y");

  // Change its palette
  plot.palette("dark2");

  plot.legend().hide();

  // Draw the helix curve
  plot.drawCurve(x, y).lineColor("orange");

  // Show the plot in a pop-up window
  plot.show();

  // Save the plot to a PDF file
  plot.save("example.png");

}