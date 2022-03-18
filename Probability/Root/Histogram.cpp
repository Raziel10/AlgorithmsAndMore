
void Histogram(double t,double p1,double p2, double p3, double p4, double p5, double p6){
    delete gROOT->FindObject("h");
    TH1F* h = new TH1F("h","Another Dice",6,0,6);
    TRandom1* r = new TRandom1();

    double v = 0; 
    if ((p1 + p2 + p3 + p4 + p5 + p6) > 1){
        return;
    }

    for(int i  = 0; i < t ; i++){
        v = r->Rndm();
        if(v <= (p1)){
            v = 0;
        }else if((v > (p1)) && (v <= (p1 + (p2)))){
            v = 1;
        }
        else if((v > (p1 + (p2))) && (v <= (p1 + p2 + p3))){
            v = 2;
        }
        else if((v > (p1 + p2 + p3)) && (v <= (p1 + p2 + p3 + p4))){
            v = 3;
        }
        else if((v > (p1 + p2 + p3 + p4)) && (v <= (p1 + p2 + p3 + p4 + p5))){
            v = 4;
        }
        else if((v > (p1 + p2 + p3 + p4 + p5)) && (v <= (p1 + p2 + p3 + p4 + p5 + p6))){
            v = 5;
        }

        h->Fill(v);
    }
    h->GetYaxis()->SetRangeUser(0,t+(t*0.1));
    h->GetXaxis()->SetBinLabel(1,"1");
    h->GetXaxis()->SetBinLabel(2,"2");
    h->GetXaxis()->SetBinLabel(3,"3");
    h->GetXaxis()->SetBinLabel(4,"4");
    h->GetXaxis()->SetBinLabel(5,"5");
    h->GetXaxis()->SetBinLabel(6,"6");
    h->Draw();

}
