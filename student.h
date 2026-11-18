
#pragma once
#include <iostream>
#include <string>


namespace SeoMinchae2649083
{
    class student
    {
        //private
        std::string name{};
        int id{};
        int score{};
        char grade{};

        void testID()
        { 
            if(1000000 > id || id > 9999999)
            {
                std::cout << "Invalid Id \n";
                std::exit(1);
            }

        }

        // void testGrade()
        // {
        //     if(grade < 'A' || grade > 'F')
        //     {
        //         std::cout << "Invalid Grade \n";
        //         std::exit(1);
        //     }
        // }


        void calGrade()
        {
        }


        void testScore()
        {
            if(score < 0 || score >100)
            {
                std::cout << "Invalid Score \n";
                std::exit(1);
            }

        }
        
        public: 
        student(const std::string& n = "no name yet", int d = 1234567, int s = 0, char g = 'F')
        :name{n}, id{d}, score{s}, grade{g}
        {testID(); 
            // testGrade(); 
            testScore();}

        void setName(const std::string& n){name=n;}
        void setID(int d)
        {id =d; testID();}
        void setScore(int s)
        {score =s; testScore();}
        void setGrade(char g)
        {grade =g;}

        void input(std::istream& is = std::cin)
        {
            std::cout << "Enter name:";
            std::getline(is >> std::ws, name);
            std::cout << "Enter id:";
            is >> id; 
            testID();
            std::cout << "Enter score:";
            is >> score; 
            testScore();
            // std::cout << "Enter grade:";
            // std::cin >> grade;
            // testGrade();
            calGrade();

        }
        
        
        friend std::istream& operator>>(std::istream& is, student& s)
        {
            s.input(is);
            return is;
        }

        

// const
        void print(std::ostream& os = std::cout) const
        {
        os << name << " ( " << id << " ) ";
        os.width(3); os.fill(0);
        os << score << " ( " << grade << " ) \n";
        }
        
        
        
        friend std::ostream& operator<<(std::ostream& os, const student& s)
        {
            s.print(os);
            return os;
        }
        
        const std::string getName() const{return name;}
        int getId() const {return id;}
        int getScore() const {return score;}
        int getGrade() const {return grade;}

        student& operator++() 
        {
            ++score;
            return *this;
            //student{name, id, ++score, grade};
        }

        student operator++(int)
    
            {
                student temp{*this};
                ++(*this);
                return temp;
            }

         friend bool operator==(const student& s1, const student& s2)
         {
           return s1.id == s2.id;
         }

         friend int operator+(const student& s1, const student& s2)
         {
            return s1.score + s2.id;
         }

         student& operator+=(int plusScore)
         { 
            this->score += plusScore;
            return *this;
         }

       


    //https://classroom50.org/cppclass-2026-37275/cppclass-2026-37275-03/assignments/assignment2/accept

    };

}

