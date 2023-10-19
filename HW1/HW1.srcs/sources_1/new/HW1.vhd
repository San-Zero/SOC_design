----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 2023/09/21 15:21:58
-- Design Name: 
-- Module Name: HW1 - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.ALL;
use IEEE.std_logic_arith.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity HW1 is
    Port ( clk : in STD_LOGIC;
           rst : in STD_LOGIC;
           led_o : out STD_LOGIC_VECTOR(7 downto 0)
           );
end HW1;

architecture Behavioral of HW1 is
signal clk_cnt:std_logic_vector(26 downto 0);
signal led:std_logic_vector(7 downto 0);
signal clk_1:std_logic;

begin
    led_o <= led;
    clk_1 <= clk_cnt(23);
    
    led_cnt:process(clk, rst)begin
        if rst = '0' then
            led <= (others => '0');
        elsif clk_1 = '1' and clk_1'event then
            led <= led + '1';
        end if;
    end process;
    
    div_clk:process(clk, rst)begin
        if rst = '0' then
            clk_cnt <= (others => '0');
        elsif clk = '1' and clk'event then
            clk_cnt <= clk_cnt + '1';
        end if;
    end process;
end Behavioral;
