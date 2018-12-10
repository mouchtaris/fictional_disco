# vim: et ts=2 sw=2
require "./logging"
require "./logger"

class A
  include Logging

  def initialize(
    @argv : Array(String)
  )
    super()
  end

  def main
    log.info "Hello. This is the Source Management System -- Aperture IT"
  end
end

A.new(ARGV).main
