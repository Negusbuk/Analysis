void Loop()
{
  std::ifstream ifile("measurements.txt");
  std::ofstream ofile("results.txt");
  std::string name, filename;
  int irr, sample;
  int j = 0;
  
  std::string cmd;
  
  gSystem->Exec("mkdir backup");
  gSystem->Exec("cp process.C calibration.txt backup");
  
  while (ifile >> name >> irr >> sample >> filename) {
    std::string dir = filename.erase(filename.length()-4, 4);
    std::cout << "processing " << dir << std::endl;
    
    cmd = "cp " + dir + "/* .";
    //std::cout << cmd << std::endl;
    gSystem->Exec(cmd.c_str());
    
    cmd = "root -l -b -q process.C";
    //std::cout << cmd << std::endl;
    gSystem->Exec(cmd.c_str());
    
    cmd = "mv Analysis.png " + dir;
    gSystem->Exec(cmd.c_str());
    
    ofile << name << "\t" << irr << "\t" << sample << "\t" << filename; 
    
    double value;
    std::ifstream fitresults("fitresults.txt");
    for (int i=0;i<5;++i) {
      fitresults >> value; ofile << "\t" << Form("%9.6f", value);
    }
    fitresults.close();
    ofile << std::endl;
    
    j++;
    //if (j==5) break;
  }
  
  gSystem->Exec("cp backup/process.C .");
  gSystem->Exec("cp backup/calibration.txt .");
  gSystem->Exec("rm -r backup");
}