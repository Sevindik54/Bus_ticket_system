#include <iostream>
using namespace std;
class rezervasyon{
	private:
		int otobusNO;
		string kalkis,varis,nerden,nereye,ad;
		int koltuk[32]={0};
		string isimler[32];   ///0-31
	public:
		void ekle();
		void Hgoster();
		void gosterID();
		void rezerve();
		void rapor();
}bus[10];
int o=0;
void rezervasyon::ekle(){
	cout<<"Otobus no giriniz:";
	cin>>bus[o].otobusNO;
	cout<<"Sofor ismi giriniz";
	cin>>bus[o].ad;
	o++;
}
void rezervasyon::Hgoster(){
	for(int i=0;i<o;i++){
		cout<<"Otobus no:   "<<bus[i].otobusNO<<endl;
		cout<<"Sofor isim:  "<<bus[i].ad<<endl;
	}
}
void rezervasyon::gosterID(){
	int id;
	cout<<"Otobus no giriniz";
	cin>>id;
	for(int i=0;i<o;i++){
		if(id==bus[i].otobusNO){
			cout<<"Otobus no:   "<<bus[i].otobusNO<<endl;
			cout<<"Sofor isim:  "<<bus[i].ad<<endl;
			break;
		}	
	}
	
}

void rezervasyon::rezerve(){
	int id,koltukNo;
	cout<<"Otobus no giriniz";
	cin>>id;
	int i;
	for(i=0;i<o;i++){
		if(id==bus[i].otobusNO){
			break;
		}	
	}
	///rezervasyon
	cout<<"koltuk no giriniz";
	cin>>koltukNo;
	if(koltukNo>32){
		cout<<"No yok";
	}else{
		if(bus[i].koltuk[koltukNo-1]==0){
			///rezervasyon
			cout<<"yolcu ismi giriniz";
			cin>>bus[i].isimler[koltukNo-1];
			bus[i].koltuk[koltukNo-1]=-1;
		}else{
			cout<<"koltuk full";
		}
	}

}
void rezervasyon::rapor()
{
	int id,koltukNo;
	cout<<"Otobus no giriniz";
	cin>>id;
	int i;
	for(i=0;i<o;i++){
		if(id==bus[i].otobusNO){
			break;
		}	
	}
	///i
	for(int j=0;j<32;j++){
		if(bus[i].koltuk[j]==0){
			///bos
			cout<<"Koltuk"<<j<<"bos"<<endl;
		}
		else{
			cout<<"Koltuk"<<j<<bus[i].isimler[j]<<" icin rezerve edilmistir"<<endl;
			//full
		}
	}
}

int main(){

	int menu;
	while(1){
		cout<<"1. otobus ekle 2.rezervasyon 3.rapor 4.tum otobusler 5.otobus rapor 6. cikis";	
		cin>>menu;
		switch(menu){
			case 1:bus[o].ekle();
				break;
				case 2:bus[o].rezerve();
				break;
			case 3:bus[o].gosterID();
				break;
			case 4:bus[o].Hgoster();
				
				break;
			case 5:bus[o].rapor();
				
			break;
			case 6:exit(1);
			break;
		}
	}
	
}
