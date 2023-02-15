#include "GUI.h"

System::Void BalaziMatusAUS2::GUI::nacitajDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    aNacitavac->nacitajInformacie("2 Územné èlenenie SR.csv", "1 Obce SR.csv");
    aTabulka = aNacitavac->getObce();
    nacitajUdajeDoDataGrid(aTabulka);
}

System::Void BalaziMatusAUS2::GUI::nacitajUdajeDoDataGrid(structures::Table<std::string, UzemnaJednotka*>* pTabulka)
{
    std::string data;
    int pocet;
    double plocha;

    String^ sysString;
    double riadok;

    for (auto item : *pTabulka) {
        riadok = dataGridView1->Rows->Add();
        DataGridViewRow^ row = dataGridView1->Rows[riadok];

        //Nazov
        data = item->accessData()->getNazov();
        sysString = gcnew String(data.c_str());
        row->Cells[0]->Value = sysString;

        //Okres
        data = item->accessData()->getJeVOkrese()->getNazov();
        sysString = gcnew String(data.c_str());
        row->Cells[1]->Value = sysString;

        //Kraj
        data = item->accessData()->getJeVKraji()->getNazov();
        sysString = gcnew String(data.c_str());
        row->Cells[2]->Value = sysString;

        //Stat
        data = item->accessData()->getJeVState()->getNazov();
        sysString = gcnew String(data.c_str());
        row->Cells[3]->Value = sysString;

        //Predprod
        pocet = item->accessData()->getPocetPredprodObyv();
        row->Cells[4]->Value = pocet;

        //Prod
        pocet = item->accessData()->getPocetProdObyv();
        row->Cells[5]->Value = pocet;

        //Poprod
        pocet = item->accessData()->getPocetPoprodObyv();
        row->Cells[6]->Value = pocet;

        //Obyv
        pocet = item->accessData()->getPocetObyv();
        row->Cells[7]->Value = pocet;

        //Vymera
        plocha = item->accessData()->getVymera();
        row->Cells[8]->Value = plocha;

        //Plocha
        plocha = item->accessData()->getZastavanaPlocha();
        row->Cells[9]->Value = plocha;

        //Zastavanost
        plocha = item->accessData()->getZastavanost();
        row->Cells[10]->Value = plocha;
    }
}

System::Void BalaziMatusAUS2::GUI::vypisInfo(Color clr, String^ text)
{
    richTextBox1->SelectionColor = clr;
    richTextBox1->AppendText(text + Environment::NewLine);
}

System::Void BalaziMatusAUS2::GUI::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (comboBox1->SelectedIndex == 1) {
        aTyp = Typ::OBEC;
        aTabulka = aNacitavac->getObce();
        button1->Enabled = true;
    }
    else if (comboBox1->SelectedIndex == 2) {
        aTyp = Typ::OKRES;
        aTabulka = aNacitavac->getOkresy();
        button1->Enabled = true;
    }
    else if (comboBox1->SelectedIndex == 3) {
        aTyp = Typ::KRAJ;
        aTabulka = aNacitavac->getKraje();
        button1->Enabled = true;
    }
    else if (comboBox1->SelectedIndex == 4) {
        aTyp = Typ::STAT;
        aTabulka = aNacitavac->getStaty();
        button1->Enabled = true;
    }
    else {
        aTyp = Typ::OBEC;
        aTabulka = aNacitavac->getObce();
        button1->Enabled = true;
    }
}

System::Void BalaziMatusAUS2::GUI::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    dataGridView1->Rows->Clear();
    richTextBox1->Clear();
    aZoradenaTabulka->clear();

    aFilterTyp = new FilterUJTyp(aKriteriumTyp, aTyp);
    aZlozenyFilter->pridajFilter(aFilterTyp);

    if (aPodlaNazvu) {
        aPodlaNazvu = false;
        System::String^ sysString = textBox1->Text;
        std::string data = msclr::interop::marshal_as<std::string>(sysString);
        aFiltrovac->vyfiltrujTabulkuPodlaNazvu(*aTabulka, aZlozenyFilter, *aCistaTabulka, data);
    }
    else {
        aFiltrovac->vyfiltrujTabulku(*aTabulka, aZlozenyFilter, *aCistaTabulka);
    }
    
    nacitajUdajeDoDataGrid(aCistaTabulka);

    for (auto item : *aCistaTabulka) {
        aZoradenaTabulka->insert(item->getKey(), item->accessData());
    }

    aZlozenyFilter->odstranVsetkyFiltre();
   
    aCistaTabulka->clear();
    
    textBox1->Clear();
    textBox2->Clear();

    button1->Enabled = false;
    button2->Enabled = true;
    button5->Enabled = true;
    button6->Enabled = true;
    
    //numericUpDown1->ResetText();
    //numericUpDown2->ResetText();
    numericUpDown1->Enabled = false;
    numericUpDown2->Enabled = false;

    //comboBox1->ResetText();
    //comboBox2->ResetText();
    //comboBox3->ResetText();
    comboBox3->Enabled = true;
}

System::Void BalaziMatusAUS2::GUI::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    System::String^ sysString = textBox1->Text;
    std::string data = msclr::interop::marshal_as<std::string>(sysString);
}

System::Void BalaziMatusAUS2::GUI::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::String^ sysString = textBox1->Text;
    aNazovUzemnejJednotky = textBox1->Text;
    std::string data = msclr::interop::marshal_as<std::string>(sysString);
    aFilterNazov = new FilterUJNazov(aKriteriumNazov, data);
    aZlozenyFilter->pridajFilter(aFilterNazov);
    aPodlaNazvu = true;
    button2->Enabled = false;
    button1->Enabled = true;
}

System::Void BalaziMatusAUS2::GUI::comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (comboBox2->SelectedIndex == 0) {
        aVzostupne = true;
    }
    else if (comboBox2->SelectedIndex == 1) {
        aVzostupne = false;
    }
    else {
        aVzostupne = true;
    }
}

System::Void BalaziMatusAUS2::GUI::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    dataGridView1->Rows->Clear();    

    if (aVzostupne) {
        if (radioButton1->Checked) {
            aTriedenieNazov->sort(*aZoradenaTabulka, *aKriteriumNazov, aVzostupne);
        }
        if (radioButton2->Checked) {
            aTriedeniePocetObyv->sort(*aZoradenaTabulka, *aKriteriumPocetObyvatelov, aVzostupne);
        }
        if (radioButton3->Checked) {
            aTriedenieZastavanost->sort(*aZoradenaTabulka, *aKriteriumZastavanost, aVzostupne);
        }
        nacitajUdajeDoDataGrid(aZoradenaTabulka);
    }
    if (!aVzostupne) {
        if (radioButton1->Checked) {
            aTriedenieNazov->sort(*aZoradenaTabulka, *aKriteriumNazov, aVzostupne);
        }
        if (radioButton2->Checked) {
            aTriedeniePocetObyv->sort(*aZoradenaTabulka, *aKriteriumPocetObyvatelov, aVzostupne);
        }
        if (radioButton3->Checked) {
            aTriedenieZastavanost->sort(*aZoradenaTabulka, *aKriteriumZastavanost, aVzostupne);
        }
        nacitajUdajeDoDataGrid(aZoradenaTabulka);
    }    
}

System::Void BalaziMatusAUS2::GUI::button4_Click(System::Object^ sender, System::EventArgs^ e)
{

    aCistaTabulka->clear();
    aZoradenaTabulka->clear();
    textBox1->Clear();
    textBox2->Clear();

    button2->Enabled = true;
    button5->Enabled = true;
    button6->Enabled = true;
    button1->Enabled = false;
    comboBox3->Enabled = true;
    dataGridView1->Rows->Clear();
    
    aTabulka = aNacitavac->getObce();

    nacitajUdajeDoDataGrid(aTabulka);
}

System::Void BalaziMatusAUS2::GUI::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    System::String^ sysString = textBox2->Text;
    std::string data = msclr::interop::marshal_as<std::string>(sysString);
}

System::Void BalaziMatusAUS2::GUI::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::String^ sysString = textBox2->Text;
    std::string data = msclr::interop::marshal_as<std::string>(sysString);

    if (aNacitavac->getOkresy()->containsKey(data)) {
       aVyssiUzemCelok = (*aNacitavac->getOkresy())[data];
       aKritCelok = true;
    }
    else if (aNacitavac->getKraje()->containsKey(data)) {
       aVyssiUzemCelok = (*aNacitavac->getKraje())[data];
       aKritCelok = true;
    }
    else if (aNacitavac->getStaty()->containsKey(data)) {
       aVyssiUzemCelok = (*aNacitavac->getStaty())[data];
       aKritCelok = true;
    }
    else {
       aKritCelok = false;
    }

    if (aKritCelok == true) {
        button5->Enabled = false;
        button1->Enabled = true;
        richTextBox1->Clear();
        vypisInfo(Color::Green, "Nasla sa zhoda!");
        aKriteriumPrislusnost->setVyssiUzemnyCelok(aVyssiUzemCelok);
        aFilterPrislusnost = new FilterUJPrislusnost(aKriteriumPrislusnost, true);
        aZlozenyFilter->pridajFilter(aFilterPrislusnost);
    }
    else {
        vypisInfo(Color::Red, "Nenasla sa zhoda!");
    }
}

System::Void BalaziMatusAUS2::GUI::comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (comboBox3->SelectedIndex == 0) {
        button1->Enabled = true;
        numericUpDown1->Enabled = true;
        numericUpDown1->DecimalPlaces = 0;
        numericUpDown2->DecimalPlaces = 0;
        comboBox3->Enabled = false;
        numericUpDown1->Enabled = true;
        numericUpDown2->Enabled = true;
    }
    else if (comboBox3->SelectedIndex == 1) {
        button1->Enabled = true;
        numericUpDown1->DecimalPlaces = 2;
        numericUpDown2->DecimalPlaces = 2;
        comboBox3->Enabled = false;
        numericUpDown1->Enabled = true;
        numericUpDown2->Enabled = true;
    }
}

System::Void BalaziMatusAUS2::GUI::numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    aOd = Decimal::ToInt32(numericUpDown1->Value);
}

System::Void BalaziMatusAUS2::GUI::numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    aDo = Decimal::ToInt32(numericUpDown2->Value);
}

System::Void BalaziMatusAUS2::GUI::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (comboBox3->SelectedIndex == 0) {
        aOd = Decimal::ToInt32(numericUpDown1->Value);
        aDo = Decimal::ToInt32(numericUpDown2->Value);
        aFilterPocetObyvatelov = new FilterUJPocetObyvatelov(aKriteriumPocetObyvatelov, aOd, aDo);
        aZlozenyFilter->pridajFilter(aFilterPocetObyvatelov);
        button6->Enabled = false;
    }
    if (comboBox3->SelectedIndex == 1) {
        aOd = Decimal::ToDouble(numericUpDown1->Value);
        aDo = Decimal::ToDouble(numericUpDown2->Value);
        aFilterZastavanost = new FilterUJZastavanost(aKriteriumZastavanost, aOd, aDo);
        aZlozenyFilter->pridajFilter(aFilterZastavanost);
        button6->Enabled = false;
    }
}


