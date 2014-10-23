void GenerateTrees()
{
  std::ifstream ifile("measurements.txt");
  std::string name, filename;
  int irr, sample;
  
  std::string cmd;
  
  while (ifile >> name >> irr >> sample >> filename) {
    std::string dir = filename;
    dir.erase(filename.length()-6, 6);
    std::string path = "/scratch/measurements/" + dir + "/" + filename;
    std::cout << "processing " << path << std::endl;
    
    cmd = "thermoDAQ2Root " + path;
    //std::cout << cmd << std::endl;
    gSystem->Exec(cmd.c_str());
  }
}
