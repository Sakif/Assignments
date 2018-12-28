const csv2json = require('csvtojson')
const fs = require('fs')
const path = require('path')

const converter = (csvPath = 'customer-data.csv') => {
	const jsonPath = csvPath.split('.')[0] + '.json'
	csv2json().fromFile(path.join(__dirname, csvPath)).then((json) => {
		console.log('CSV data converted to JSON.');
		const jsonString = JSON.stringify(json)
		fs.writeFileSync(path.join(__dirname, jsonPath), jsonString)
		console.log(`Data saved to ${jsonPath}`);
	})
}

converter(process.argv[2])