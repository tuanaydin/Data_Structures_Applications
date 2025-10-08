// Tuana Aydýn
//1316200027
//Veri Yapýlarý Week 1 Asssignment
//Pointer ve Array Uygulamalarý 07.10.2025

#include <iostream>
#include <string>
using namespace std;

//Struct Definition
// Bu kýsýmda struct tanýmlandý
//Ödevde belirtilen içerikler eklendi
//name, age, GPA
 struct Student
{
    string name;
    int age;
    float GPA;
};
 
 //Kullanýcýdan Verilerin Alýnmasý ve Kaydedilmesi

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
            i--; // Geçersiz giriþ durumunda tekrar ayný öðrencinin verisinin giriþi 
        }
        cout << "GPA: ";
		cin >> (*(arr + i)).GPA;
		//GPA deðerinin 0.0 ile 4.0 arasýnda olup olmadýðýnýn kontrolü saðlamak için
        if(((*(arr + i)).GPA>4.0) || ((*(arr + i)).GPA < 0))
        {
            cout << "Hatali GPA degeri girdiniz. GPA 0.0 ile 4.0 arasinda olmalidir." << endl;
            i--; // Geçersiz giriþ durumunda tekrar ayný öðrencinin verisinin giriþi 
		}
        
     }
 }

 /*Sýralama Fonksiyonu
 -Basit olmasý nedeniyle Selection Sort kullanýldý
 -Assignment'ta artan sýraya göre istenmiþti.Bu nedenle GPA'ye göre küçükten büyüðe sýralandý.
 -geeksforgeeks.org adresinden faydalanýldý*/

  void sortByGPA (Student* arr, int n) 
  {
      for (int a = 0; a < n - 1; a++) 
      {
		  //Baþlanhýçta en küçük eleman olarak ilk eleman kabul edildi.Kýyaslama iþlemi için
          int minIndex = a;
          
          //Sýralama yapýlma iþlemi yapýlmayan kýsýmdan baþlanýr
          for (int i = a + 1; i < n; i++) 
		  {//Sonraki indexlerdeki elemanlarla kýyaslama yapýlýr
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
  //Eðer GPA'leri Büyüklük Sýrasýna Göre Sýralamak Ýstenirse Aþaðýdaki Kod Kullanýlabilir
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
       cout << "Ogrenci Listesi (GPA'nin Küçükten Büyüðe Siralanmasina Gore):" << endl;
	   for (int i = 0; i < n; i++) {
		   cout << i + 1 << ". " << (*(arr + i)).name << ", " << (*(arr + i)).age << " yasinda, GPA: " << (*(arr + i)).GPA << endl;
	   }
   }

int main()
{
    //Giriþ Mesajý
	cout << "Ogrenci Kayit Sistemi" << endl;
	int n; 
	//Öðrenci Sayýsýnýn Alýnmasýnýn gerçekleþtirildiði kýsým
	cout << "Lutfen bilgisi kayit edilip siralanacak ogrenci sayisini giriniz: ";
	//Kullanýcý giriþi
    cin >> n;
	// n sayýsýnýn sýfýrdan küçük veya eþit olmasý istenmeyen durum
    //Bu durumun kontrolü saðlanýr
    
    if (n <= 0) {
        cout << "Hatali ogrenci sayisi girdiniz. Ogrenci sayisi sifira esit ya da sifirdan kucuk olamaz" << endl;
        return 1;
	}
    
    //Dinamik dizi oluþturarak boyutun n sayýsýna eþit olmasýný saðlarýz
    //Assignmette students dizisine kayýt edilmesi istenmiþti
	Student* students = new Student[n];
	
    //Fonksiyonlarýn çaðrýlmasý
    inputStudents(students,n);
	sortByGPA(students,n);
    printStudents(students,n);

	delete[] students; // Dinamik olarak ayrýlan belleði serbest býrakma Memory Leak'i önlemek için
    
    return 0;
}