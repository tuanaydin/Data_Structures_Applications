// Tuana Ayd�n
//1316200027
//Veri Yap�lar� Week 1 Asssignment
//Pointer ve Array Uygulamalar� 07.10.2025

#include <iostream>
#include <string>
using namespace std;

//Struct Definition
// Bu k�s�mda struct tan�mland�
//�devde belirtilen i�erikler eklendi
//name, age, GPA
 struct Student
{
    string name;
    int age;
    float GPA;
};
 
 //Kullan�c�dan Verilerin Al�nmas� ve Kaydedilmesi

 void inputStudents (Student* arr, int n) 
 {
     for (int i = 0; i < n; i++) 
     {
        cout << i + 1 << " Numarali ogrenci icin detaylari giriniz:" << endl;
        cout << "Isim (Name): ";
        cin >> (*(arr + i)).name;
        cout << "Yas (Age): ";
        cin >> (*(arr+i)).age;
        if (((*(arr + i)).age < 0))
        {
            cout << "Hatali yas degeri girdiniz. Yas sifirdan buyul olmalidir." << endl;
            i--; // Ge�ersiz giri� durumunda tekrar ayn� ��rencinin verisinin giri�i 
        }
        cout << "GPA: ";
		cin >> (*(arr + i)).GPA;
		//GPA de�erinin 0.0 ile 4.0 aras�nda olup olmad���n�n kontrol� sa�lamak i�in
        if(((*(arr + i)).GPA>4.0) || ((*(arr + i)).GPA < 0))
        {
            cout << "Hatali GPA degeri girdiniz. GPA 0.0 ile 4.0 arasinda olmalidir." << endl;
            i--; // Ge�ersiz giri� durumunda tekrar ayn� ��rencinin verisinin giri�i 
		}
        
     }
 }

 /*S�ralama Fonksiyonu
 -Basit olmas� nedeniyle Selection Sort kullan�ld�
 -Assignment'ta artan s�raya g�re istenmi�ti.Bu nedenle GPA'ye g�re k���kten b�y��e s�raland�.
 -geeksforgeeks.org adresinden faydalan�ld�*/

  void sortByGPA (Student* arr, int n) 
  {
      for (int a = 0; a < n - 1; a++) 
      {
		  //Ba�lanh��ta en k���k eleman olarak ilk eleman kabul edildi.K�yaslama i�lemi i�in
          int minIndex = a;
          
          //S�ralama yap�lma i�lemi yap�lmayan k�s�mdan ba�lan�r
          for (int i = a + 1; i < n; i++) 
		  {//Sonraki indexlerdeki elemanlarla k�yaslama yap�l�r
              if ((*(arr + i)).GPA < (*(arr + minIndex)).GPA) 
              {
                  minIndex = i;
              }
          }
          if (minIndex != a) 
          {
              Student temp = *(arr + a);
              *(arr + a) = *(arr + minIndex);
              *(arr + minIndex) = temp;
          }
	  }
  }
  //E�er GPA'leri B�y�kl�k S�ras�na G�re S�ralamak �stenirse A�a��daki Kod Kullan�labilir
  /*void sortByGPA(Student* arr, int n)
  {
      for (int a = 0; a < n - 1; a++) 
      {
          int maxIndex = a;
          for (int i = a + 1; i < n; i++) 
          {
              if ((*(arr + i)).GPA > (*(arr + maxIndex)).GPA) 
              {
                  maxIndex = i;
              }
          }
          if (maxIndex != a) 
          {
              Student temp = *(arr + a);
              *(arr + a) = *(arr + maxIndex);
              *(arr + maxIndex) = temp;
          }
      }
  }
 */

  //Listeleme Fonksiyonu
   void printStudents (Student* arr, int n) 
   {
       cout << "Ogrenci Listesi (GPA'nin K���kten B�y��e Siralanmasina Gore):" << endl;
	   for (int i = 0; i < n; i++) {
		   cout << i + 1 << ". " << (*(arr + i)).name << ", " << (*(arr + i)).age << " yasinda, GPA: " << (*(arr + i)).GPA << endl;
	   }
   }

int main()
{
    //Giri� Mesaj�
	cout << "Ogrenci Kayit Sistemi" << endl;
	int n; 
	//��renci Say�s�n�n Al�nmas�n�n ger�ekle�tirildi�i k�s�m
	cout << "Lutfen bilgisi kayit edilip siralanacak ogrenci sayisini giriniz: ";
	//Kullan�c� giri�i
    cin >> n;
	// n say�s�n�n s�f�rdan k���k veya e�it olmas� istenmeyen durum
    //Bu durumun kontrol� sa�lan�r
    
    if (n <= 0) {
        cout << "Hatali ogrenci sayisi girdiniz. Ogrenci sayisi sifira esit ya da sifirdan kucuk olamaz" << endl;
        return 1;
	}
    
    //Dinamik dizi olu�turarak boyutun n say�s�na e�it olmas�n� sa�lar�z
    //Assignmette students dizisine kay�t edilmesi istenmi�ti
	Student* students = new Student[n];
	
    //Fonksiyonlar�n �a�r�lmas�
    inputStudents(students,n);
	sortByGPA(students,n);
    printStudents(students,n);

	delete[] students; // Dinamik olarak ayr�lan belle�i serbest b�rakma Memory Leak'i �nlemek i�in
    
    return 0;
}