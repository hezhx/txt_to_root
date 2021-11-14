void txt2root()
{

	ifstream inputdata;
	inputdata.open("output_info.txt");

	if (inputdata.fail())
	{
		cout << "sorry,couldn't read." << endl;
		exit(1);
	}

	//event is useless 
	//Int_t event = 0.;

	Float_t EG = 0.;
	Float_t ES = 0;
	//Float_t I = 0.;


	Int_t lines = 0.;
	
    	string line;
    	ifstream myfile("output_info.txt");

    	if(myfile.is_open()){
        	while(!myfile.eof()){
            	getline(myfile,line);
            	lines++;
        }
        myfile.close();
    }

	cout << "Lines: " << lines << endl;

	TFile *f = new TFile("info.root", "RECREATE");
	TTree *T1 = new TTree("T1", "data from output_info.txt");

	T1->Branch("EG", &EG, "EG/F");	
	T1->Branch("ES", &ES, "ES/F");

	for (Int_t i = 0; i <= lines; i++)
	{
		inputdata 
			>> EG
			>> ES;

		T1->Fill();
	}

	T1->Write();
	f->Close();
	inputdata.close();
}
