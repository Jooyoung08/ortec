void conv_root(){

	TFile *ofile = new TFile("Sn124-data.root","RECREATE");
	TTree *otree = new TTree("cc1","cc1");
	double group; int nfile;
	double rtime; double ltime;
	int ch; int val;
	otree->Branch("group",&group,"group/D");
	otree->Branch("nfile",&nfile,"nfile/I");
	otree->Branch("rtime",&rtime,"rtime/D");
	otree->Branch("ltime",&ltime,"ltime/D");
	otree->Branch("ch",&ch,"ch/I");
	otree->Branch("val",&val,"val/I");

	group = 0; nfile = 0; rtime = 0; ltime = 0; ch = 0; val = 0;
	double nch = 8194;
	double data[8194] = {0};
	double predata[8194] = {0};

	for(int i=0; i<136; i++){ //135 files in 200805
		group = 200806;
		fstream file;
		file.open(Form("./200806_CMD203_Enriched_124Sn.%03i.txt",i),ios::in);
		nfile = i;

		if(i==0){
			for(int j=0; j<nch; j++){
				file >> data[j];
			}
			for(int l=0; l<nch; l++){
				predata[l] = data[l];
			}
			rtime = data[0];
			ltime = data[1];
			for(int k=2; k<nch; k++){
				ch = k-2;
				val = data[k];
				otree->Fill();
				data[k] = 0;
			}
			data[0] = 0; data[1] = 0;
		}

		else{
			for(int j=0; j<nch; j++){
				file >> data[j];
			}
			rtime = data[0]-predata[0];
			ltime = data[1]-predata[1];
			predata[0] = data[0];
			predata[1] = data[1];
			for(int k=2; k<nch; k++){
				ch = k-2;
				val = data[k] - predata[k];
				otree->Fill();
				predata[k] = data[k];
				data[k] = 0;
			}
			data[0] = 0; data[1] = 0;
		}
	}//end of 200806

	for(int i=0; i<62; i++){ //61 files in 200904
		group = 200904;
		fstream file2;
		file2.open(Form("./200904_CMD203_Enriched_124Sn.%03i.txt",i),ios::in);
		nfile = i;

		if(i==0){
			for(int j=0; j<nch; j++){
				file2 >> data[j];
			}
			for(int l=0; l<nch; l++){
				predata[l] = data[l];
			}
			rtime = data[0];
			ltime = data[1];
			for(int k=2; k<nch; k++){
				ch = k-2;
				val = data[k];
				otree->Fill();
				data[k] = 0;
			}
			data[0] = 0; data[1] = 0;
		}

		else{
			for(int j=0; j<nch; j++){
				file2 >> data[j];
			}
			rtime = data[0]-predata[0];
			ltime = data[1]-predata[1];
			predata[0] = data[0];
			predata[1] = data[1];
			for(int k=2; k<nch; k++){
				ch = k-2;
				val = data[k] - predata[k];
				otree->Fill();
				predata[k] = data[k];
				data[k] = 0;
			}
			data[0] = 0; data[1] = 0;
		}
	}//end of 200904

	for(int i=0; i<265; i++){ //264 files in 200918
		group = 200918;
		fstream file3;
		file3.open(Form("./200918_CMD203_Enriched_124Sn.%03i.txt",i),ios::in);
		nfile = i;

		if(i==0){
			for(int j=0; j<nch; j++){
				file3 >> data[j];
			}
			for(int l=0; l<nch; l++){
				predata[l] = data[l];
			}
			rtime = data[0];
			ltime = data[1];
			for(int k=2; k<nch; k++){
				ch = k-2;
				val = data[k];
				otree->Fill();
				data[k] = 0;
			}
			data[0] = 0; data[1] = 0;
		}

		else{
			for(int j=0; j<nch; j++){
				file3 >> data[j];
			}
			rtime = data[0]-predata[0];
			ltime = data[1]-predata[1];
			predata[0] = data[0];
			predata[1] = data[1];
			for(int k=2; k<nch; k++){
				ch = k-2;
				val = data[k] - predata[k];
				otree->Fill();
				predata[k] = data[k];
				data[k] = 0;
			}
			data[0] = 0; data[1] = 0;
		}
	}//end of 201113

	for(int i=0; i<52; i++){ //51 files in 201113
		group = 201113;
		fstream file4;
		file4.open(Form("./201113_CMD203_Enriched_124Sn.%03i.txt",i),ios::in);
		nfile = i;

		if(i==0){
			for(int j=0; j<nch; j++){
				file4 >> data[j];
			}
			for(int l=0; l<nch; l++){
				predata[l] = data[l];
			}
			rtime = data[0];
			ltime = data[1];
			for(int k=2; k<nch; k++){
				ch = k-2;
				val = data[k];
				otree->Fill();
				data[k] = 0;
			}
			data[0] = 0; data[1] = 0;
		}

		else{
			for(int j=0; j<nch; j++){
				file4 >> data[j];
			}
			rtime = data[0]-predata[0];
			ltime = data[1]-predata[1];
			predata[0] = data[0];
			predata[1] = data[1];
			for(int k=2; k<nch; k++){
				ch = k-2;
				val = data[k] - predata[k];
				otree->Fill();
				predata[k] = data[k];
				data[k] = 0;
			}
			data[0] = 0; data[1] = 0;
		}
	}//end of 201113

	otree->Write();	
	ofile->Write();
	ofile->Close();
	delete ofile;
}
