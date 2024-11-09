#include <vector>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override;

	double eval() const override;

	const char * name() const override;

private:
	double m_min;
};

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::min()} {
	}

	void update(double next) override;

	double eval() const override;

	const char * name() const override;

private:
	double m_max;
};

class Mean : public IStatistics {
public:
	Mean() : m_sum{0.0}, m_counter{0} {
	}

	void update(double next) override;

	double eval() const override;

	const char * name() const override;

private:
	double m_sum;
    int m_counter;
};

class Std : public IStatistics {
public:
	Std() : m_sum{0.0}{
	}

	void update(double next) override;

	double eval() const override;

	const char * name() const override;

private:
	std::vector<double> list;
    double m_sum;
};

class Pc90 : public IStatistics {
public:
    Pc90() {}

    void update(double next) override;

    double eval() const override;
    const char* name() const override;
private:
    std::vector<double> list;
};
