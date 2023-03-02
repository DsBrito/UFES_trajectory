#ifndef PSH_H
#define PSH_H

/**
 * @brief Impressão de prompt da psh (passaport shell)
 * 
 * @return void 
 */
void printPrompt(); 

/**
 * @brief Tratamento dos sinais/vírus da psh, grupo de vacinados e grupos de não vacinados.
 * 
 * @param int 
 * @return void
 */
void configuraMascaraSinais(int tipo);

/**
 * @brief Tratamento dos sinais/vírus bloqueados na psh
 * 
 * @return void
 */
void tratadorSinaisBloqueados_psh();

/**
 * @brief Tratamento da nova cepa identificada  (SIGUSR1).
 * 
 * @return void
 */
void tratadorSIGUSR1();

/**
 * @brief Impressão do mago no terminal
 * 
 * @return void
 */
void printMago();

#endif