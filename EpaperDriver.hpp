/* 
 * Hardware driver for Pervasive Displays' e-paper displays
 * 
 * Copyright (c) Project Nayuki
 * https://www.nayuki.io/
 */

#include <cstdint>


class EpaperDriver final {
	
	/*---- Fields ----*/
	
	// Pin configuration
	public: int chipSelectPin = -1;
	
	
	
	/*---- SPI methods ----*/
	
	// Sends a command over SPI to the device, containing exactly one data byte.
	// This cannot be used for writes that contain less or more than one data byte.
	private: void spiWrite(std::uint8_t cmdIndex, std::uint8_t cmdData);
	
	
	// Sends a command over SPI to the device, containing exactly one dummy byte,
	// reading the one-byte response, and returning it. This cannot
	// be used for reads that contain less or more than one data byte.
	private: std::uint8_t spiRead(std::uint8_t cmdIndex);
	
	
	// Sends a command over SPI to the device, reading the one-byte response,
	// and returning the chip-on-glass driver identification value.
	private: std::uint8_t spiGetId();
	
	
	// Sends the given two raw bytes over SPI to the device, returning the byte read from
	// the latter byte transfer, and holding the chip select pin low during the transfers.
	private: std::uint8_t spiRawPair(std::uint8_t b0, std::uint8_t b1);
	
};