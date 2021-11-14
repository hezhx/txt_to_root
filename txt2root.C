void txt2root(){

	ifstream inputdata;
	inputdata.open("output_info.txt");
	// 打开txt/dat文件，文件格式形如：
	// 0.27842  	83.1989  	
	// 1.489    	80.9743  	
	// 2.76231  	30.7807  	
	// 0.209114  	-0.019098  	
	// 0.314717  	82.4491  	
	// 0.114408  	40.0227  	
	// 0.0990437  	48.7835  	
	// 0.395912  	24.626  	
	// -0.00047	-0.0327192  	
	// 0.207558  	51.5393  	
	// 0.288928  	0.0195822  	
	// 1.89434  	0.0404032  	
	// 1.46468  	75.7249
	// 每一列为一个参量

	if (inputdata.fail())
	{
		cout << "sorry,couldn't read." << endl;
		exit(1);
	}

	// event is useless 
	// Int_t event = 0.;

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
	// 读取文件行数（也即事件数）并输出

	TFile *f = new TFile("info.root", "RECREATE");
	TTree *T1 = new TTree("T1", "data from output_info.txt");
	// 创建info.root的文件，其tree名为T1
	
	T1->Branch("EG", &EG, "EG/F");	
	T1->Branch("ES", &ES, "ES/F");
	// T1有txt列数个branch
	
	for (Int_t i = 0; i <= lines; i++)
	{
		inputdata 
			>> EG
			>> ES;

		T1->Fill();
	}
	// 为T1写入数据

	T1->Write();
	f->Close();
	inputdata.close();
	// 关闭T1、文件
}
