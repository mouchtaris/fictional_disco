# vim: et ts=2 sw=2

module Logging
  def initialize
    @logger = Logger.new(STDERR, self.class.name)
  end

  def log
    @logger
  end
end
