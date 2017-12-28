/*
 * name:        LIDAR-Lite-v3
 * description: A compact, high-performance optical distance measurement sensor from Garmin™.
 * manuf:       Garmin
 * version:     0.1
 * url:         https://static.garmin.com/pumac/LIDAR_Lite_v3_Operation_Manual_and_Technical_Specifications.pdf
 * date:        2017-12-15
 * author       https://chisl.io/
 * file:        LIDAR-Lite-v3.hpp
 */

#include <cinttypes>

/* Derive from class LIDAR_Lite_v3_Base and implement the read and write functions! */

/* LIDAR-Lite-v3: A compact, high-performance optical distance measurement sensor from Garmin™. */
class LIDAR_Lite_v3_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	virtual uint16_t read16(uint16_t address, uint16_t n=16) = 0;  // 16 bit read
	virtual void write(uint16_t address, uint16_t value, uint16_t n=16) = 0;  // 16 bit write
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG ACQ_COMMAND                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG ACQ_COMMAND:
	 * Faster distance measurements can be performed by omitting the receiver bias correction routine. Measurement accuracy and sensitivity are adversely affected if conditions change (e.g. target distance, device temperature, and optical noise). To achieve good performance at high measurement rates receiver bias correction must be performed periodically. The recommended method is to do so at the beginning of every 100 sequential measurement commands.
	 */
	struct ACQ_COMMAND
	{
		static const uint16_t __address = 0;
		
		/* Bits ACQ_COMMAND: */
		struct ACQ_COMMAND_
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
			static const uint8_t RESET = 0; // All registers return to default values
			static const uint8_t NO_BIAS = 3; // Take distance measurement without receiver bias correction
			static const uint8_t BIAS = 4; // Take distance measurement with receiver bias correction
		};
	};
	
	/* Set register ACQ_COMMAND */
	void setACQ_COMMAND(uint8_t value)
	{
		write(ACQ_COMMAND::__address, value, 8);
	}
	
	/* Get register ACQ_COMMAND */
	uint8_t getACQ_COMMAND()
	{
		return read8(ACQ_COMMAND::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG STATUS                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG STATUS:
	 * System status
	 */
	struct STATUS
	{
		static const uint16_t __address = 1;
		
		/* Bits unused_0: */
		struct unused_0
		{
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits ProcessErrorFlag: */
		struct ProcessErrorFlag
		{
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t OK = 0b0; // No error detected
			static const uint8_t ERR = 0b1; // System error detected during measurement
		};
		/* Bits HealthFlag: */
		struct HealthFlag
		{
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t ERR = 0b0; // Error detected
			static const uint8_t OK = 0b1; // Reference and receiver bias are operational
		};
		/* Bits SecondaryReturnFlag: */
		struct SecondaryReturnFlag
		{
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t NO = 0b0; // No secondary return detected
			static const uint8_t YES = 0b1; // Secondary return detected in correlation record
		};
		/* Bits InvalidSignalFlag: */
		struct InvalidSignalFlag
		{
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t YES = 0b0; // Peak detected
			static const uint8_t NO = 0b1; // Peak not detected in correlation record, measurement is invalid
		};
		/* Bits SignalOverOwFlag: */
		struct SignalOverOwFlag
		{
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t NO = 0b0; // Signal data has not over owed
			static const uint8_t YES = 0b1; // Signal data in correlation record has reached the maximum value before over ow. This occurs with a strong received signal strength
		};
		/* Bits ReferenceOverOwFlag: */
		struct ReferenceOverOwFlag
		{
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t NO = 0b0; // Reference data has not over owed
			static const uint8_t YES = 0b1; // Reference data in correlation record has reached the maximum value before over ow. This occurs periodically
		};
		/* Bits BusyFlag: */
		struct BusyFlag
		{
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t READY = 0b0; // Device is ready for new command
			static const uint8_t BUSY = 0b1; // Device is busy taking a measurement
		};
	};
	
	/* Set register STATUS */
	void setSTATUS(uint8_t value)
	{
		write(STATUS::__address, value, 8);
	}
	
	/* Get register STATUS */
	uint8_t getSTATUS()
	{
		return read8(STATUS::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG SIG_COUNT_VAL                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG SIG_COUNT_VAL:
	 * Maximum acquisition count
	 */
	struct SIG_COUNT_VAL
	{
		static const uint16_t __address = 2;
		
		/* Bits SIG_COUNT_VAL: */
		struct SIG_COUNT_VAL_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b10000000; // 8'h80
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register SIG_COUNT_VAL */
	void setSIG_COUNT_VAL(uint8_t value)
	{
		write(SIG_COUNT_VAL::__address, value, 8);
	}
	
	/* Get register SIG_COUNT_VAL */
	uint8_t getSIG_COUNT_VAL()
	{
		return read8(SIG_COUNT_VAL::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                        REG ACQ_CONFIG_REG                                         *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACQ_CONFIG_REG:
	 * Acquisition mode control
	 */
	struct ACQ_CONFIG_REG
	{
		static const uint16_t __address = 4;
		
		/* Bits unused_0: */
		struct unused_0
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits EnableReferenceProcess: */
		struct EnableReferenceProcess
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t ENABLE = 0b0; // Enable reference process during measurement
			static const uint8_t DISABLE = 0b1; // Disable reference process during measurement
		};
		/* Bits Delay: */
		struct Delay
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t DEFAULT = 0b0; // Use default delay for burst and free running mode
			static const uint8_t FROM_MEASURE_DELAY = 0b1; // Use delay from MEASURE_DELAY (0x45) for burst and free running mode
		};
		/* Bits Reference: */
		struct Reference
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t ENABLE = 0b0; // Enable reference filter, averages 8 reference measurements for increased consistency
			static const uint8_t DISABLE = 0b1; // Disable reference filter
		};
		/* Bits MeasurementQuickTermination: */
		struct MeasurementQuickTermination
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t ENABLE = 0b0; // Enable measurement quick termination. Device will terminate distance measurement early if it anticipates that the signal peak in the correlation record will reach maximum value.
			static const uint8_t DISABLE = 0b1; // Disable measurement quick termination.
		};
		/* Bits ReferenceAcquisition: */
		struct ReferenceAcquisition
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t DEFAULT = 0b0; // Use default reference acquisition count of 5.
			static const uint8_t FROM_REF_COUNT_VAL = 0b1; // Use reference acquisition count from REF_COUNT_VAL (0x12).
		};
		/* Bits ModeSelectPinFunctionControl: */
		struct ModeSelectPinFunctionControl
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000011; // [0,1]
			static const uint8_t DEFAULT = 0b00; // Default PWM mode. Pull pin low to trigger measurement, device will respond with an active high output with a duration of 10us/cm.
			static const uint8_t STATUS_OUTPUT = 0b01; // Status output mode. Device will drive pin active high while busy. Can be used to interrupt host device.
			static const uint8_t FIXED_DELAY = 0b10; // Fixed delay PWM mode. Pulling pin low will not trigger a measurement. 11: Oscillator output mode. Nominal 31.25 kHz output. The accuracy of the silicon oscillator in the device is generally within 1% of nominal. This affects distance measurements proportionally and can be measured to apply a compensation factor.
		};
	};
	
	/* Set register ACQ_CONFIG_REG */
	void setACQ_CONFIG_REG(uint8_t value)
	{
		write(ACQ_CONFIG_REG::__address, value, 8);
	}
	
	/* Get register ACQ_CONFIG_REG */
	uint8_t getACQ_CONFIG_REG()
	{
		return read8(ACQ_CONFIG_REG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG VELOCITY                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG VELOCITY:
	 * Velocity measurement output
	 */
	struct VELOCITY
	{
		static const uint16_t __address = 9;
		
		/* Bits Velocity: */
		/* Velocity measurement output. The difference between the current measurement and the previous one, signed (2’s complement) value in centimeters.  */
		struct Velocity
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register VELOCITY */
	void setVELOCITY(uint8_t value)
	{
		write(VELOCITY::__address, value, 8);
	}
	
	/* Get register VELOCITY */
	uint8_t getVELOCITY()
	{
		return read8(VELOCITY::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG PEAK_CORR                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG PEAK_CORR:
	 * Peak value in correlation record
	 */
	struct PEAK_CORR
	{
		static const uint16_t __address = 12;
		
		/* Bits Value: */
		/* The value of the highest peak in the correlation record.  */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register PEAK_CORR */
	void setPEAK_CORR(uint8_t value)
	{
		write(PEAK_CORR::__address, value, 8);
	}
	
	/* Get register PEAK_CORR */
	uint8_t getPEAK_CORR()
	{
		return read8(PEAK_CORR::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG NOISE_PEAK                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG NOISE_PEAK:
	 * Correlation record noise floor
	 */
	struct NOISE_PEAK
	{
		static const uint16_t __address = 13;
		
		/* Bits Value: */
		/* A measure of the noise in the correlation record. Will be slightly above the third highest peak.  */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register NOISE_PEAK */
	void setNOISE_PEAK(uint8_t value)
	{
		write(NOISE_PEAK::__address, value, 8);
	}
	
	/* Get register NOISE_PEAK */
	uint8_t getNOISE_PEAK()
	{
		return read8(NOISE_PEAK::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                       REG SIGNAL_STRENGTH                                        *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG SIGNAL_STRENGTH:
	 * Received signal strength
	 */
	struct SIGNAL_STRENGTH
	{
		static const uint16_t __address = 14;
		
		/* Bits Value: */
		/* Received signal strength calculated from the value of the highest peak in the correlation record and how many acquisitions were performed.  */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register SIGNAL_STRENGTH */
	void setSIGNAL_STRENGTH(uint8_t value)
	{
		write(SIGNAL_STRENGTH::__address, value, 8);
	}
	
	/* Get register SIGNAL_STRENGTH */
	uint8_t getSIGNAL_STRENGTH()
	{
		return read8(SIGNAL_STRENGTH::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG FULL_DELAY                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG FULL_DELAY:
	 * Distance measurement high and low byte
	 */
	struct FULL_DELAY
	{
		static const uint16_t __address = 15;
		
		/* Bits Value: */
		/* Distance measurement result in centimeters, high and low byte.  */
		struct Value
		{
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register FULL_DELAY */
	void setFULL_DELAY(uint16_t value)
	{
		write(FULL_DELAY::__address, value, 16);
	}
	
	/* Get register FULL_DELAY */
	uint16_t getFULL_DELAY()
	{
		return read16(FULL_DELAY::__address, 16);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                       REG OUTER_LOOP_COUNT                                        *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG OUTER_LOOP_COUNT:
	 * Burst measurement count control
	 */
	struct OUTER_LOOP_COUNT
	{
		static const uint16_t __address = 17;
		
		/* Bits Value: */
		/*
		 * 0x00-0x01: One measurement per distance measurement command.
		 * 0x02-0xfe: Repetition count per distance measurement command.
		 * 0xff: Indefinite repetitions after initial distance measurement command.
		 * See ACQ_CONFIG_REG (0x04) and MEASURE_DELAY (0x45) for non- default automatic repetition delays.
		 */
		struct Value
		{
			static const uint8_t dflt = 0b00000001; // 8'b1
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OUTER_LOOP_COUNT */
	void setOUTER_LOOP_COUNT(uint8_t value)
	{
		write(OUTER_LOOP_COUNT::__address, value, 8);
	}
	
	/* Get register OUTER_LOOP_COUNT */
	uint8_t getOUTER_LOOP_COUNT()
	{
		return read8(OUTER_LOOP_COUNT::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG REF_COUNT_VAL                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG REF_COUNT_VAL:
	 * Reference acquisition count
	 */
	struct REF_COUNT_VAL
	{
		static const uint16_t __address = 18;
		
		/* Bits Value: */
		/* Non-default number of reference acquisitions during measurement. ACQ_ CONFIG_REG (0x04) bit 2 must be set.  */
		struct Value
		{
			static const uint8_t dflt = 0b00000101; // 8'b101
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register REF_COUNT_VAL */
	void setREF_COUNT_VAL(uint8_t value)
	{
		write(REF_COUNT_VAL::__address, value, 8);
	}
	
	/* Get register REF_COUNT_VAL */
	uint8_t getREF_COUNT_VAL()
	{
		return read8(REF_COUNT_VAL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                       REG LAST_DELAY_HIGH                                        *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG LAST_DELAY_HIGH:
	 * Previous distance measurement high byte
	 */
	struct LAST_DELAY_HIGH
	{
		static const uint16_t __address = 20;
		
		/* Bits Value: */
		/* Previous distance measurement result in centimeters, high byte.  */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register LAST_DELAY_HIGH */
	void setLAST_DELAY_HIGH(uint8_t value)
	{
		write(LAST_DELAY_HIGH::__address, value, 8);
	}
	
	/* Get register LAST_DELAY_HIGH */
	uint8_t getLAST_DELAY_HIGH()
	{
		return read8(LAST_DELAY_HIGH::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                        REG LAST_DELAY_LOW                                         *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG LAST_DELAY_LOW:
	 * Previous distance measurement low byte
	 */
	struct LAST_DELAY_LOW
	{
		static const uint16_t __address = 21;
		
		/* Bits Value: */
		/* Previous distance measurement result in centimeters, low byte.  */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register LAST_DELAY_LOW */
	void setLAST_DELAY_LOW(uint8_t value)
	{
		write(LAST_DELAY_LOW::__address, value, 8);
	}
	
	/* Get register LAST_DELAY_LOW */
	uint8_t getLAST_DELAY_LOW()
	{
		return read8(LAST_DELAY_LOW::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG UNIT_ID_HIGH                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG UNIT_ID_HIGH:
	 * Serial number high byte
	 */
	struct UNIT_ID_HIGH
	{
		static const uint16_t __address = 22;
		
		/* Bits Value: */
		/* Unique serial number of device, high byte.  */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register UNIT_ID_HIGH */
	void setUNIT_ID_HIGH(uint8_t value)
	{
		write(UNIT_ID_HIGH::__address, value, 8);
	}
	
	/* Get register UNIT_ID_HIGH */
	uint8_t getUNIT_ID_HIGH()
	{
		return read8(UNIT_ID_HIGH::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG UNIT_ID_LOW                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG UNIT_ID_LOW:
	 * Serial number low byte
	 */
	struct UNIT_ID_LOW
	{
		static const uint16_t __address = 23;
		
		/* Bits Value: */
		/* Unique serial number of device, high byte.  */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register UNIT_ID_LOW */
	void setUNIT_ID_LOW(uint8_t value)
	{
		write(UNIT_ID_LOW::__address, value, 8);
	}
	
	/* Get register UNIT_ID_LOW */
	uint8_t getUNIT_ID_LOW()
	{
		return read8(UNIT_ID_LOW::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG I2C_ID_HIGH                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_ID_HIGH:
	 * Write serial number high byte for I2C address unlock
	 */
	struct I2C_ID_HIGH
	{
		static const uint16_t __address = 24;
		
		/* Bits Value: */
		/* Write the value in UNIT_ID_HIGH (0x16) here as part of enabling a non- default I2C address. See I2C_ID_LOW (0x19) and I2C_SEC_ADDR (0x1a).  */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_ID_HIGH */
	void setI2C_ID_HIGH(uint8_t value)
	{
		write(I2C_ID_HIGH::__address, value, 8);
	}
	
	/* Get register I2C_ID_HIGH */
	uint8_t getI2C_ID_HIGH()
	{
		return read8(I2C_ID_HIGH::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG I2C_ID_LOW                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG I2C_ID_LOW:
	 * Write serial number low byte for I2C address unlock
	 */
	struct I2C_ID_LOW
	{
		static const uint16_t __address = 25;
		
		/* Bits Value: */
		/* Write the value in UNIT_ID_LOW (0x17) here as part of enabling a non-default I2C address. See I2C_ID_HIGH (0x18) and I2C_SEC_ADDR (0x1a).  */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_ID_LOW */
	void setI2C_ID_LOW(uint8_t value)
	{
		write(I2C_ID_LOW::__address, value, 8);
	}
	
	/* Get register I2C_ID_LOW */
	uint8_t getI2C_ID_LOW()
	{
		return read8(I2C_ID_LOW::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG I2C_SEC_ADDR                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG I2C_SEC_ADDR:
	 * Write new I2C address after unlock
	 */
	struct I2C_SEC_ADDR
	{
		static const uint16_t __address = 26;
		
		/* Bits Value: */
		/*
		 * Non-default I2C address.
		 * Available addresses are 7-bit values with a ‘0’ in the least signi cant bit (even hexadecimal numbers).
		 * I2C_ID_HIGH (0x18) and I2C_ID_LOW (0x19) must have the correct value for the device to respond to the non-default I2C address.
		 */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_SEC_ADDR */
	void setI2C_SEC_ADDR(uint8_t value)
	{
		write(I2C_SEC_ADDR::__address, value, 8);
	}
	
	/* Get register I2C_SEC_ADDR */
	uint8_t getI2C_SEC_ADDR()
	{
		return read8(I2C_SEC_ADDR::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                       REG THRESHOLD_BYPASS                                        *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG THRESHOLD_BYPASS:
	 * Peak detection threshold bypass
	 * The default valid measurement detection algorithm is based on the peak value,
	 * signal strength, and noise in the correlation record. This can be overridden
	 * to become a simple threshold criterion by setting a non-zero value. Recommended
	 * non-default values are 0x20 for higher sensitivity with more frequent erroneous
	 * measurements, and 0x60 for reduced sensitivity and fewer erroneous measurements.
	 */
	struct THRESHOLD_BYPASS
	{
		static const uint16_t __address = 28;
		
		/* Bits Value: */
		/*
		 * 0x01-0xff: Set simple threshold for valid measurement detection.
		 * Values 0x20-0x60 generally perform well.
		 */
		struct Value
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
			static const uint8_t DEFAULT = 0x0; // Use default valid measurement detection algorithm based on the peak value, signal strength, and noise in the correlation record.
		};
	};
	
	/* Set register THRESHOLD_BYPASS */
	void setTHRESHOLD_BYPASS(uint8_t value)
	{
		write(THRESHOLD_BYPASS::__address, value, 8);
	}
	
	/* Get register THRESHOLD_BYPASS */
	uint8_t getTHRESHOLD_BYPASS()
	{
		return read8(THRESHOLD_BYPASS::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG I2C_CONFIG                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG I2C_CONFIG:
	 * Default address response control
	 */
	struct I2C_CONFIG
	{
		static const uint16_t __address = 30;
		
		/* Bits ResponseControl: */
		struct ResponseControl
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t DEFAULT = 0b0; // Device will respond to I2C address 0x62. Device will also respond to non-default address if con gured successfully. See I2C_ID_HIGH (0x18), I2C_ID_LOW (0x19), and I2C_SEC_ADDR (0x1a).
			static const uint8_t NON_DEFAULT = 0b1; // Device will only respond to non-default I2C address. It is recommended to con gure the non-default address  rst, then use the non-default address to write to this register, ensuring success.
		};
	};
	
	/* Set register I2C_CONFIG */
	void setI2C_CONFIG(uint8_t value)
	{
		write(I2C_CONFIG::__address, value, 8);
	}
	
	/* Get register I2C_CONFIG */
	uint8_t getI2C_CONFIG()
	{
		return read8(I2C_CONFIG::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG COMMAND                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG COMMAND:
	 * State command
	 */
	struct COMMAND
	{
		static const uint16_t __address = 64;
		
		/* Bits TestMode: */
		/*
		 * Select correlation memory bank in ACQ_SETTINGS (0x5d) prior to enabling test mode.
		 * Once test mode is enabled, read CORR_DATA (0x52) and CORR_DATA_ SIGN (0x53) in one transaction (read from 0xd2). The memory index is incremented automatically and successive reads produce sequential data.
		 */
		struct TestMode
		{
			static const uint8_t mask = 0b00000111; // [0,1,2]
			static const uint8_t DISABLE = 0b00; // Test mode disable, resume normal operation
			static const uint8_t ENABLE = 0b111; // Test mode enable, allows download of correlation record
		};
	};
	
	/* Set register COMMAND */
	void setCOMMAND(uint8_t value)
	{
		write(COMMAND::__address, value, 8);
	}
	
	/* Get register COMMAND */
	uint8_t getCOMMAND()
	{
		return read8(COMMAND::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG MEASURE_DELAY                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG MEASURE_DELAY:
	 * Delay between automatic measurements
	 */
	struct MEASURE_DELAY
	{
		static const uint16_t __address = 69;
		
		/* Bits Value: */
		/* Non-default delay after completion of measurement before automatic retrigger, in burst and continuous modes. ACQ_CONFIG_REG (0x04) bit 5 must be set. Value 0xc8 corresponds to 10 Hz repetition rate and 0x14 to roughly 100 Hz.  */
		struct Value
		{
			static const uint8_t dflt = 0b00010100; // 8'b10100
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register MEASURE_DELAY */
	void setMEASURE_DELAY(uint8_t value)
	{
		write(MEASURE_DELAY::__address, value, 8);
	}
	
	/* Get register MEASURE_DELAY */
	uint8_t getMEASURE_DELAY()
	{
		return read8(MEASURE_DELAY::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG PEAK_BCK                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG PEAK_BCK:
	 * Second largest peak value in correlation record
	 */
	struct PEAK_BCK
	{
		static const uint16_t __address = 76;
		
		/* Bits Value: */
		/* The value of the second highest peak in the correlation record.  */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register PEAK_BCK */
	void setPEAK_BCK(uint8_t value)
	{
		write(PEAK_BCK::__address, value, 8);
	}
	
	/* Get register PEAK_BCK */
	uint8_t getPEAK_BCK()
	{
		return read8(PEAK_BCK::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CORR_DATA                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CORR_DATA:
	 * Correlation record data low byte
	 */
	struct CORR_DATA
	{
		static const uint16_t __address = 82;
		
		/* Bits Value: */
		/* Correlation record data low byte. See CORR_DATA_SIGN (0x53), ACQ_ SETTINGS (0x5d), and COMMAND (0x40).  */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register CORR_DATA */
	void setCORR_DATA(uint8_t value)
	{
		write(CORR_DATA::__address, value, 8);
	}
	
	/* Get register CORR_DATA */
	uint8_t getCORR_DATA()
	{
		return read8(CORR_DATA::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                        REG CORR_DATA_SIGN                                         *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG CORR_DATA_SIGN:
	 * Correlation record data high byte
	 */
	struct CORR_DATA_SIGN
	{
		static const uint16_t __address = 83;
		
		/* Bits Value: */
		/* Correlation record data high byte. Correlation record data is a 2’s complement 9-bit value, and must be sign extended to be formatted as a 16-bit 2’s complement value. Thus when repacking the two bytes obtained for the I2C transaction, set the high byte to 0xff if the LSB of the high byte is one.  */
		struct Value
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register CORR_DATA_SIGN */
	void setCORR_DATA_SIGN(uint8_t value)
	{
		write(CORR_DATA_SIGN::__address, value, 8);
	}
	
	/* Get register CORR_DATA_SIGN */
	uint8_t getCORR_DATA_SIGN()
	{
		return read8(CORR_DATA_SIGN::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG ACQ_SETTINGS                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACQ_SETTINGS:
	 * Correlation record memory bank select
	 */
	struct ACQ_SETTINGS
	{
		static const uint16_t __address = 93;
		
		/* Bits Bank: */
		struct Bank
		{
			static const uint8_t mask = 0b11000000; // [6,7]
			static const uint8_t BANK = 0b11; // Access correlation memory bank. Write prior to test mode enable, see COMMAND (0x40).
		};
	};
	
	/* Set register ACQ_SETTINGS */
	void setACQ_SETTINGS(uint8_t value)
	{
		write(ACQ_SETTINGS::__address, value, 8);
	}
	
	/* Get register ACQ_SETTINGS */
	uint8_t getACQ_SETTINGS()
	{
		return read8(ACQ_SETTINGS::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG POWER_CONTROL                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG POWER_CONTROL:
	 * Power state control
	 */
	struct POWER_CONTROL
	{
		static const uint16_t __address = 101;
		
		/* Bits Sleep: */
		struct Sleep
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t SLEEP = 0b1; // Device Sleep, wakes upon I2C transaction. Registers are reinitialized, wakeup time similar to full reset using enable pin.
			static const uint8_t WAKE = 0b0; // Device awake
		};
		/* Bits ReceiverCircuit: */
		struct ReceiverCircuit
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t DISABLE = 0b1; // Disable receiver circuit
			static const uint8_t ENABLE = 0b0; // Enable receiver circuit. Receiver circuit stabilizes by the time a measurement can be performed.
		};
	};
	
	/* Set register POWER_CONTROL */
	void setPOWER_CONTROL(uint8_t value)
	{
		write(POWER_CONTROL::__address, value, 8);
	}
	
	/* Get register POWER_CONTROL */
	uint8_t getPOWER_CONTROL()
	{
		return read8(POWER_CONTROL::__address, 8);
	}
	
};
