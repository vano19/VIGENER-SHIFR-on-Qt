#include "vigener.h"

Vigener::Vigener(){}

Vigener::Vigener(std::string n)
{   char* name ;
    std::copy(n.begin(),n.end(),name);
    QFile file(name);
    if (file.open(QIODevice::ReadOnly))
    {   QTextStream in(&file);
        QString buf= in.readLine();

        while (file.atEnd())
        {
            for (int i(0); i < sizeof(buf); i++)
            {
                if (buf.at(i)<'?' && buf.at(i)>'?')
                {
                    if (buf.at(i) >= '?' && buf.at(i) <= '?')
                    {
                        char v = static_cast<char>(buf.at(i).toLatin1());
                        afile += v - 0x20;
                    }
                    else if (buf.at(i) >= '?' && buf.at(i) <= '?')
                    {   char v = static_cast<char>(buf.at(i).toLatin1());
                        afile += v - 0x70;
                    }

                }
                else afile += buf.at(i);
            }
        }
    }
    file.close();
}

Vigener::~Vigener()
{

}
void Vigener::num_lett() const
{   QFile outf("text.txt");
    if(outf.open(QIODevice::Append|QIODevice::WriteOnly))
    {
        std::string str = static_cast<std::string>(afile.toStdString());
        std::map <std::string,int> chars;
        std::map <std::string,int>::iterator begin, at, end;
        for(unsigned int i = 0; i < str.size(); i++){
            std::string  concat;
            concat +=str[i];
            concat +=str[i+1];
            chars[concat]++;
            i++;
            begin = chars.begin();
            end  = chars.end();
        }

        for(at = begin; at != end; at++)
        {   std::string line = at->first;
            line+="\t";
            line+=at->second;
            line+="\n";
            QByteArray data;
            QDataStream out(&data,QIODevice::WriteOnly);
            out<<quint16(data.size());
            for(int i = 0; i < data.size(); i++)
                out << data[i];
            outf.write(data);
        }

        outf.close();
    }
}

void Vigener::goShifr()
{
    char abc[32] ={'?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?',
                   '?','?','?','?','?','?','?','?','?','?'};

    std::string key = "";
    std::string key_on_s = "";

    int x = 0, y = 0;

    char dublicat;

    int shift = 0;
    char **tabula_recta = new char *[32];
    for (int i=0;i<32;i++)
        tabula_recta[i] = new char [32];


    for (int i = 0; i < 32; i++)
        for (int j = 0; j < 32; j++)
        {
            shift = j + i;
            if (shift >= 32) shift = shift % 32;
            tabula_recta[i][j] = abc[shift];
        }


    std::string str;

    str =static_cast<std::string>(afile.toStdString());

    //    cout<<"Enter key encryption\n";
    //                cin>>key;

    for (int i = 0; i < str.size(); i++)
    {
        key_on_s += key[i % key.length()];
    }
    for (int i = 0; str[i]!='\0'; i++)
    {
        int l = 0;
        while (l < 32)
        {
            if (key_on_s[i] == tabula_recta[l][0])
            {
                x = l;
            }
            l++;
        }
        l = 0;

        while (l < 32)
        {
            if ((str[i]) == tabula_recta[0][l])
            {
                y = l;
            }
            l++;
        }

        per.push_back(tabula_recta[x][y]);
    }

    for (std::vector<char>::iterator it = per.begin() ; it!=per.end(); ++it)
        //   file<<*it;

        for(int i=0;i<32;i++)
            delete tabula_recta[i];
    delete tabula_recta;
}


