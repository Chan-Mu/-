/* USER CODE BEGIN PV */

char n = 0;
//组合数
char i = 0;

//注射次数10-180
int count = 0;

//串口发送内容
uint8_t uart1_str[100];

//注射器型号
char model[3] = {1,3,5};

//药液容量
double capacity[5] = {0.8,2,3,4,5};

//注射剂量
double dose = 0;

/* USER CODE END PV */

void Calculation(void);

int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  
  HAL_Delay(2000);
  Calculation();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

void Calculation(void)
{
  
  sprintf((char*)uart1_str,"各组合单次注射剂量统计\r\n");   
  HAL_UART_Transmit(&huart1,(unsigned char *)uart1_str, sizeof(uart1_str),50);
  
  if( capacity[n] == 0.8 )
  {
    while( (count < 180) && ( capacity[n] == 0.8 ) )
    {
      i++;
      count = count + 10;
      dose = capacity[n] / count;
      
      sprintf((char*)uart1_str,"组合%2.0d: 剂量选择 %2.1f/%dml; 次数选择 %3.0d次; 单次注射剂量 %0.4fml\r\n",i,capacity[n],model[0],count,dose);   
      HAL_UART_Transmit(&huart1,(unsigned char *)uart1_str, sizeof(uart1_str),0xff);
      
      if( count == 180 )
      {
        count = 0;
        n++;
      }
    }
  }
  
  if( capacity[n] == 2 )
  {
    while( (count < 180) && ( capacity[n] == 2 ) )
    {
      i++;
      count = count + 10;
      dose = capacity[n] / count;
      
      sprintf((char*)uart1_str,"组合%2.0d: 剂量选择 %2.1f/%dml; 次数选择 %3.0d次; 单次注射剂量 %0.4fml\r\n",i,capacity[n],model[1],count,dose);   
      HAL_UART_Transmit(&huart1,(unsigned char *)uart1_str, sizeof(uart1_str),0xff);
      
      if( count == 180 )
      {
        count = 0;
        n++;
      }
    }
  }
  
  if( capacity[n] == 3 )
  {
    while( (count < 180) && ( capacity[n] == 3 ) )
    {
      i++;
      count = count + 10;
      dose = capacity[n] / count;
      
      sprintf((char*)uart1_str,"组合%2.0d: 剂量选择 %2.1f/%dml; 次数选择 %3.0d次; 单次注射剂量 %0.4fml\r\n",i,capacity[n],model[1],count,dose);   
      HAL_UART_Transmit(&huart1,(unsigned char *)uart1_str, sizeof(uart1_str),0xff);
      
      if( count == 180 )
      {
        count = 0;
        n++;
      }
    }
  }
  
  if( capacity[n] == 4 )
  {
    while( (count < 180) && ( capacity[n] == 4 ) )
    {
      i++;
      count = count + 10;
      dose = capacity[n] / count;
      
      sprintf((char*)uart1_str,"组合%2.0d: 剂量选择 %2.1f/%dml; 次数选择 %3.0d次; 单次注射剂量 %0.4fml\r\n",i,capacity[n],model[2],count,dose);   
      HAL_UART_Transmit(&huart1,(unsigned char *)uart1_str, sizeof(uart1_str),0xff);
      
      if( count == 180 )
      {
        count = 0;
        n++;
      }
    }
  }
  
  if( capacity[n] == 5 )
  {
    while( (count < 180) && ( capacity[n] == 5 ) )
    {
      i++;
      count = count + 10;
      dose = capacity[n] / count;
      
      sprintf((char*)uart1_str,"组合%2.0d: 剂量选择 %2.1f/%dml; 次数选择 %3.0d次; 单次注射剂量 %0.4fml\r\n",i,capacity[n],model[2],count,dose);   
      HAL_UART_Transmit(&huart1,(unsigned char *)uart1_str, sizeof(uart1_str),0xff);
      
      if( count == 180 )
      {
        count = 0;
        n++;
      }
    }
  }
  
}
