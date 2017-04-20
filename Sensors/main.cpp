#include <cstdio>
#include <ConnectionServeur.h>
#include <BBBiolib.h>

#define BUFFER_SIZE 100
#define SAMPLE_SIZE 10

BBBIO_ADCTSC_module_ctrl(BBBIO_ADC_WORK_MODE_TIMER_INT, clk_div);

BBBIO_ADCTSC_channel_ctrl(BBBIO_ADC_AIN0, BBBIO_ADC_STEP_MODE_SW_CONTINUOUS, open_dly, sample_dly, \ BBBIO_ADC_STEP_AVG_1, buffer_AIN_0, BUFFER_SIZE);
BBBIO_ADCTSC_channel_ctrl(BBBIO_ADC_AIN1, BBBIO_ADC_STEP_MODE_SW_CONTINUOUS, open_dly, sample_dly, \ BBBIO_ADC_STEP_AVG_1, buffer_AIN_1, BUFFER_SIZE);
BBBIO_ADCTSC_channel_ctrl(BBBIO_ADC_AIN2, BBBIO_ADC_STEP_MODE_SW_CONTINUOUS, open_dly, sample_dly, \ BBBIO_ADC_STEP_AVG_1, buffer_AIN_2, BUFFER_SIZE);
BBBIO_ADCTSC_channel_ctrl(BBBIO_ADC_AIN3, BBBIO_ADC_STEP_MODE_SW_CONTINUOUS, open_dly, sample_dly, \ BBBIO_ADC_STEP_AVG_1, buffer_AIN_3, BUFFER_SIZE);


static bool initialisation(char * ip, int Poids, int newVersionMajor, int newVersionMinor, int newVersionPatch, bool newIsDebug);

void main()
{
	While(1)
	{
		if(verifRecevoirPret())
		{
				char * = recevoir();
				
				if(strcmp("VerifierCoherencePoid",) == 0) // Si trigger reçu du serveur
				{
					
					envoyer("RecupNumeroBoite");
					char * message;
					int numeroBoite;
					scanf(,"Numero%d",&numeroBoite);
					
					int boite = LectureMasse(numeroBoite*2+1) + LectureMasse(numeroBoite*2+2);
					
					
					int boite2 = LectureMasse(3) + LectureMasse(4);
		
					envoyer("RecupPoidUnitaire1");
					char * PoidUnitaire1 = recevoir();
					envoyer('RecupPoidUnitaire2");
					char * PoidUnitaire2 = recevoir();')
										
					
					int IdMed;
					int NbMed;
					scanf("VerifierCoherencePoid%d-%d",&idMed,&NbMed);
					scanf("VerifierCoherencePoid%d-%d",&idMed,&NbMed);
					
					int nbMedBoite1 = boite1 / PoidUnitaire1
					int nbMedBoite2 = boite2 / PoidUnitaire2
					
					if ( nbMedBoite1 !=  ||  nbMedBoite2 != )
					
						
				}
		}
	}
	static void fermer();
    return 0;
}

	    int LectureMasse(int NumeroCapteur);
		{
		if (NumeroCapteur ==1)
		{
			int Vfsr = buffer_AIN_0
			return Masse = (Vfsr + (float)30,72) / ((float) 1,442); 
		}
		if (NumeroCapteur ==2)
		{
			int Vfsr = buffer_AIN_1
			return Masse = (Vfsr + (float)30,72) / ((float) 1,442); 
		}
		if (NumeroCapteur ==3)
		{
			int Vfsr = buffer_AIN_2
			return Masse = (Vfsr + (float)30,72) / ((float) 1,442); 
		}
		if (NumeroCapteur ==4)
		{
			int Vfsr = buffer_AIN_3
			return masse = (Vfsr + (float)30,72) / ((float) 1,442); 
		}
		}
		
		
 /*
  * void main()
  * {
  * 	while(1)
  * 	{
  * 		if(verifRecevoirPret())
  * 		{
  * 			char * message = recevoir()
  * 			if(strcmp("",message) == 0)
  * 			{
  * 				int numero;
  * 				int compte;
  * 				scanf("MachIN%d-%d",&numero,&compte);
  * 				if(Machin)
  * 				{
  * 					envoyer("PoidCoherent");
  * 				}
  * 				else
  * 				{
  * 					envoyer("erreur");
  * 				}
  * 
  * 			}
  * 
  * 
  * 		}
  * 
  * 		udelay(10000);
  * 	}
  * }

 * /

int LectureMasse(int NumeroCapteur)
{
