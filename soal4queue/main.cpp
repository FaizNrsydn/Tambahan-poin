#include "queue.h"
using namespace std;


infotype doc1 = {"Surat Tugas", "Ayu", 10};
infotype doc2 = {"Undangan", "Sasa", 3};
infotype doc3 = {"Notula Rapat", "Ayu", 15};
infotype doc4 = {"Pedoman KPI", "Ayu", 85};
infotype doc5 = {"Presensi", "Nia", 24};

int main() {
    queue Q_Printer;
    createQueue(Q_Printer);

    cout << "=== SOAL 4: QUEUE (Antrian Printer) ===" << endl;
    
    cout << "\n INISIALISASI ANTRIAN AWAL " << endl;
    enqueue(Q_Printer, createNewElm(doc1)); 
    enqueue(Q_Printer, createNewElm(doc2));
    enqueue(Q_Printer, createNewElm(doc3)); 
    enqueue(Q_Printer, createNewElm(doc4)); 
    enqueue(Q_Printer, createNewElm(doc5));
    displayQueue(Q_Printer);

    cout << "\n==============================================" << endl;
    cout << " PENGUJIAN antriPrinter (BATAS MAKS 3) " << endl;
    
    infotype new_doc_ayu = {"Laporan Akhir", "Ayu", 50};
    antriPrinter(Q_Printer, new_doc_ayu); 

    infotype new_doc_sasa = {"Memo Internal", "Sasa", 5};
    antriPrinter(Q_Printer, new_doc_sasa);

    infotype new_doc_budi = {"Draft Proposal", "Budi", 100};
    antriPrinter(Q_Printer, new_doc_budi);

    cout << "\n--- ANTRIAN SETELAH antriPrinter ---" << endl;
    displayQueue(Q_Printer);


    cout << "\n==============================================" << endl;
    cout << " PENGUJIAN simulasiCetak (Kertas = 50) " << std::endl;
    int kertas_case_1 = 50; 
    simulasiCetak(Q_Printer, kertas_case_1);
    
    cout << "\n--- ANTRIAN SETELAH SIMULASI CETAK (Kertas 50) ---" << endl;
    displayQueue(Q_Printer);


    cout << "\n==============================================" << endl;
    cout << " PENGUJIAN simulasiCetak Lanjutan (Kertas = 30)" << endl;
    int kertas_case_2 = 30;
    simulasiCetak(Q_Printer, kertas_case_2);

    cout << "\n--- ANTRIAN AKHIR ---" << endl;
    displayQueue(Q_Printer);

    return 0;
}