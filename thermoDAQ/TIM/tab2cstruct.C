void tab2cstruct()
{
  double irr, R, dR, offset;
  int sample;
  std::ifstream ifile("plotdata.txt");
  while (ifile >> irr >> sample >> R >> dR >> offset) {
    std::cout << "  { " << Form("%+3.1f", irr) << ", "
              << Form("%+6.4f", offset) << ", "
              << sample << ", "
              << Form("%.3f", R) << ", "
              << Form("%.3f", dR) << " }," << std::endl;
  }
}