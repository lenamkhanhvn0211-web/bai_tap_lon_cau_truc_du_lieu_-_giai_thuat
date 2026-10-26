#ifndef exam_h
#define exam_h
#include<bits/stdc++.h>
#include"vector.h"
#include"cauhoi.h"
class exam{
    private:
        vectorcuatoi<cauhoi> nganhang;
        vectorcuatoi<cauhoi> giay;
        std::mt19937 rng;
        
        static int nhapdapan(char s){
            switch(toupper(s)){
                case 'A': return 0;
                case 'B': return 1;
                case 'C': return 2;
                case 'D': return 3;
                default: throw std::runtime_error("Ky tu dap an khong hop le: chi nhan A/B/C/D");
            }
        }
    public:
        exam(){
            unsigned seed=static_cast<unsigned>(
                std::chrono::high_resolution_clock::now().time_since_epoch().count());
            rng.seed(seed);
        }
        void loadFromFile(const std::string& filename) {
        std::ifstream fin(filename);
        if (!fin.is_open()) throw std::runtime_error("Khong the mo file: "+filename);
        std::string line;
        while (std::getline(fin, line)){
            if (line.empty()) continue;
            std::string content=line;
            std::string opts[4];
            for(int i=0;i<4;++i){
                if (!std::getline(fin, line)) throw std::runtime_error("File cau hoi sai dinh dang (thieu phuong an).");
                size_t dotPos=line.find('.');
                if(dotPos!=std::string::npos&&dotPos+2<=line.size()) opts[i]=line.substr(dotPos+2);
                else opts[i]=line;
            }
            if(!std::getline(fin,line)) throw std::runtime_error("File cau hoi sai dinh dang (thieu dap an dung).");
            size_t colonPos=line.find(':');
            if(colonPos==std::string::npos) throw std::runtime_error("File cau hoi sai dinh dang (thieu 'Correct:').");
            std::string ansPart=line.substr(colonPos+1);
            size_t firstNonSpace=ansPart.find_first_not_of(" \t\r");
            char ansChar=(firstNonSpace!=std::string::npos)?ansPart[firstNonSpace]:'A';
            int correctIdx=nhapdapan(ansChar);
            nganhang.push_back(cauhoi(content,opts[0],opts[1],opts[2],opts[3],correctIdx));
            std::getline(fin,line);
        }
    }
    size_t bankSize() const{
        return nganhang.size();
    }
    void generatePaper(size_t k){
        if(k>nganhang.size()) throw std::runtime_error("So cau hoi yeu cau vuot qua kho cau hoi hien co.");
        giay.clear();
        vectorcuatoi<size_t> indices;
        for(size_t i=0;i<nganhang.size();i++) indices.push_back(i);
        std::vector<size_t> tmp;
        for(size_t i=0;i<indices.size();i++) tmp.push_back(indices[i]);
        std::shuffle(tmp.begin(),tmp.end(),rng);
        for(size_t i=0;i<k;i++){
            const cauhoi& original=nganhang[tmp[i]];
            giay.push_back(original.troncauhoi(rng));
        }
    }
    int takeExamInteractive() const{
        int correctCount=0;
        int qNo=1;
        for(auto it=const_cast<vectorcuatoi<cauhoi>&>(giay).begin();it!=const_cast<vectorcuatoi<cauhoi>&>(giay).end();it++,qNo++){
            const cauhoi& q=*it;
            std::cout<<"\nCau "<<qNo<<": "<<q.getnoidung()<<"\n";
            const char labels[4]={'A','B','C','D'};
            for(int i=0;i<4;i++) std::cout<<"  "<<labels[i]<<". "<<q.getphuongan(i)<<"\n";
            std::cout<<"Tra loi (A/B/C/D): ";
            std::string ans;
            std::getline(std::cin,ans);
            if(!ans.empty()){
                int chosen=nhapdapan(ans[0]);
                if(chosen==q.getphuongandung()){
                    correctCount++;
                    std::cout<<"-> Dung!\n";
                }
                else std::cout<<"-> Sai. Dap an dung la: "<<labels[q.getphuongandung()]<< ". "<<q.getdapandung()<<"\n";
            }
        }
        return correctCount;
    }
    double scoreOn10(int correctCount) const{
        if(giay.size()==0) return 0.0;
        return (double)correctCount/(double)giay.size()*10.0;
    }
    void printPaperReversed(){
        std::cout<<"\n--- Xem lai de thi (duyet bang bo lap NGUOC) ---\n";
        int qNo=(int)giay.size();
        for(auto it=giay.rbegin();it!=giay.rend();it++,qNo--){
            const cauhoi& q=*it;
            std::cout<<"Cau "<<qNo <<": "<<q.getnoidung()<<"\n";
        }
    }
    size_t paperSize() const{
        return giay.size();
    }
};
#endif