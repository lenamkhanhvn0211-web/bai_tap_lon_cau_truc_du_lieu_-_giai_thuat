#ifndef cauhoi_h
#define cauhoi_h
#include<bits/stdc++.h>
#include"vector.h"
class cauhoi{
    private:
        std::string noidung;
        std::string phuongan[4];
        int phuongandung;
    public:
        cauhoi(){
            phuongandung=0;
        }
        cauhoi(const std::string& content,const std::string& cauA,const std::string& cauB,const std::string& cauC,const std::string& cauD,int caudung){
            this->noidung=content;
            this->phuongan[0]=cauA;
            this->phuongan[1]=cauB;
            this->phuongan[2]=cauC;
            this->phuongan[3]=cauD;
            this->phuongandung=caudung;
        }
        const std::string& getnoidung() const{
            return noidung;
        }
        const std::string& getphuongan(int i) const{
            return phuongan[i];
        }
        int getphuongandung() const{
            return phuongandung;
        }
        const std::string& getdapandung() const{
            return phuongan[phuongandung];
        }
        cauhoi troncauhoi(std::mt19937& rng) const{
            int order[4]={0,1,2,3};
            std::shuffle(order,order+4,rng);

            cauhoi q;
            q.noidung=noidung;
            int dapanmoi=0;
            for(int i=0;i<4;i++){
                q.phuongan[i]=phuongan[order[i]];
                if(order[i]==phuongandung) dapanmoi=i;
            }
            q.phuongandung=dapanmoi;
            return q;
        }
};
#endif