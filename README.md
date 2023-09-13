# Help

### 1. Clone the Repository

```bash
git clone git@github.com:mikkokiviniemi/smart-monitor.git
cd smart-monitor
```
### 2. Installing prerequisite
```bash
sudo apt install cmake g++ make
```
```bash
sudo apt-get install libcurl4-openssl-dev
```
### 3. Building app
```bash
cmake -S . -B build
```
```bash
make -C build
```
### 4. Run
```bash
build/app
```